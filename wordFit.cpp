#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <string.h>

using namespace std;

string elementSymbols[] = {"Ac",
	"Ag",
	"Al",
	"Am"
	"Ar",
	"As",
	"At",
	"Au",
	"B",
	"Ba",
	"Be",
	"Bh",
	"Bi",
	"Bk",
	"Br",
	"C",
	"Ca",
	"Cd",
	"Ce",
	"Cf",
	"Cl",
	"Cm",
	"Cn",
	"Co",
	"Cr",
	"Cs",
	"Cu",
	"Db",
	"Ds",
	"Dy",
	"Er",
	"Es",
	"Eu",
	"F",
	"Fe",
	"Fl",
	"Fm",
	"Fr",
	"Ga",
	"Gd",
	"Ge",
	"H",
	"He",
	"Hf",
	"Hg",
	"Ho",
	"Hs",
	"I",
	"In",
	"Ir",
	"K",
	"Kr",
	"La",
	"Li",
	"Lr",
	"Lu",
	"Lv",
	"Md",
	"Mg",
	"Mn",
	"Mo",
	"Mt",
	"N",
	"Na",
	"Nb",
	"Ne",
	"Ni",
	"No",
	"Np",
	"O",
	"Os",
	"P",
	"Pa",
	"Pb",
	"Pd",
	"Pm",
	"Po",
	"Pr",
	"Pt",
	"Pu",
	"Ra",
	"Rb",
	"Re",
	"Rf",
	"Rg",
	"Rh",
	"Rn",
	"Ru",
	"S",
	"Sb",
	"Sc",
	"Se",
	"Sg",
	"Si",
	"Sm",
	"Sn",
	"Sr",
	"Ta",
	"Tb",
	"Tc",
	"Te",
	"Th",
	"Ti",
	"Tl",
	"Tm",
	"U",
	"V",
	"W",
	"Xe",
	"Y",
	"Yb",
	"Zn",
	"Zr"};

//Record length of element symbol list
int elemLen = sizeof(elementSymbols)/sizeof(elementSymbols[0]);

//For a given word, return a list of lists
//Each list element is a list of element symbols that match the word string when concatenated
vector<vector <string> > findCombo(string word)
{
	vector<vector <string> > retCombo;
	int wordLen = word.length();
	//Loop through all element symbols
	for(int i=0;i<elemLen;i++)
	{
		//If the word is smaller than the elementSymbol than don't bother trying
		if (word.length() >= elementSymbols[i].length())
		{
			//Make sure characters match
			bool found = true;
			int elemLen = elementSymbols[i].length();
			for (int t=0;t<elemLen;t++)
			{
				if (tolower(elementSymbols[i][t]) != tolower(word[t]))
					found = false;
			}
			
			//If the elemental symbol can fit in the first part of the word
			if (found)
			{
				//If the word length is equal to the element symbol then simply add the element to the combo list to be return no recursion
				if (word.length() == elementSymbols[i].length())
				{
					vector<string> curElemVector;
					curElemVector.push_back(elementSymbols[i]);
					retCombo.push_back(curElemVector);
				}
				//Otherwise recurse and add the current element to each item in the result and append that to the current result list
				else
				{
					//Send remaining part of word into recursive function
					//For each result append the current element symbol and append it to each item
					//Append the resulting elements to retCombos to be returned
					vector<vector<string> > retElemVector = findCombo(word.substr(elemLen, wordLen-elemLen));
					for (int m=0;m<retElemVector.size();m++)
					{
						vector<string> curElemVector = retElemVector.at(m);
						curElemVector.insert(curElemVector.begin(), elementSymbols[i]);
						retCombo.push_back(curElemVector);
					}
				}
			}
		}
	}
	
	return retCombo;
}

//Return lowercase string version of the given string
string lowerString(string word)
{
	string retWord = "";
	for (int i=0;i<word.length();i++)
	{
		retWord.append(1, tolower(word[i]));
	}
	
	return retWord;
}
 
int main()
{	
	//Read in the words from words.txt
	vector<string> wordList;
	fstream f;
	f.open("words.txt");
	string buffer;
	getline(f, buffer);
	int wordListLen = 1;
	while(!f.eof())
	{
		wordList.push_back(buffer);
		getline(f, buffer);
		wordListLen++;
	}
	f.close();
	
	//For each word in the list run it through findCombo
	vector<vector <string> > elementWordList;
	for (int i=0;i<wordListLen;i++)
	{
		//Print each word returned from findCombo
		//Find combo returns a list of list of strings
		//each list of strings is a reconstruction of the word using elemental symbols
		elementWordList = findCombo(wordList[i]);
		for (int t=0;t<elementWordList.size();t++)
		{
			//Concatenate the elemental symbol strings into original word
			string curWord = "";
			for (int m=0;m<elementWordList.at(t).size();m++)
			{
				curWord.append(elementWordList.at(t).at(m));
			}
			
			//If there was a problem then alert the user
			if (lowerString(curWord).compare(lowerString(wordList[i])) != 0)
			{
				cout << "This word was not reconstructred properly" << endl;
				cout << wordList[i] << endl;
				cout << curWord << endl;
				cout << "Please report this error to alecmoore001@gmail.com" << endl;
				return 0;
			}
			//Otherwise just print the resulting concatenation
			else
			{
				cout << curWord << endl;
			}
		}
	}
	
	return 0;
}


