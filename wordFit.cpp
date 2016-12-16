#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <vector>

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

struct result
{
	vector<string> elementList;
	int duplicateCount;
};

void printArray(vector<string> nList)
{
	int i;
	for(i=0;i<nList.size();i++)
	{
		cout << nList[i] << endl;
	}
	printf("\n");
}

//As we return results in our recursive function, we only want to return the most unique combination of elemental symbols
//Each time a result is found it will only be returned if its uniqueness (1/number of duplicates) is greater than the lowest combination
int comboUniqueVal;
vector<result> findCombo(string word)
{
	vector<result> retCombo;
	
	int i;
	for(i=0;i<elementSymbols.length();i++)
	{
		if(word[0] == elementSymbols[i])
		{
			
		}
	}
	
	return retCombo;
}

vector<string> copyArray(vector<string> nList)
{
	vector<string> retList;
	int i;
	for(i=0;i<nList.size();i++)
	{
		retList.push_back(nList[i]);
	}
	
	return retList;
}

//Returns true if stringA is alphabetically higher than stringB
bool alphaCheck(string stringA, string stringB)
{
	int i;
	for(i=0;i<stringA.length();i++)
	{
		if(stringA[i] < stringB[i])
		{
			return true;
		}
		if(stringA[i] > stringB[i])
		{
			return false;
		}
	}
	
	return false;
}

vector<string> quickSort(vector<string> nList)
{
	vector<string> quickList = copyArray(nList);
	int sortIndex = rand() % nList.size();
	string sortValue = nList[sortIndex];
	
	vector<string> leftSort;
	vector<string> rightSort;
	//List of values equal to the index value, there will be no need to sort these just put them between the left and right sorts.
	vector<string> centerList;
	
	int i;
	for(i=0;i<nList.size();i++)
	{
		if(nList[i].length() > sortValue.length())
		{
			rightSort.push_back(nList[i]);
		}
		else if(nList[i].length() == sortValue.length())
		{
			centerList.push_back(nList[i]);
		}
		else
		{
			leftSort.push_back(nList[i]);
		}
	}
	
	if(rightSort.size() > 1)
		rightSort = quickSort(rightSort);
	if(leftSort.size() > 1)
		leftSort = quickSort(leftSort);
	
	vector<string> totalSort;
	for(i=0;i<leftSort.size();i++)
	{
		totalSort.push_back(leftSort[i]);
	}
	
	for(i=0;i<centerList.size();i++)
	{
		totalSort.push_back(centerList[i]);
	}
	
	for(i=0;i<rightSort.size();i++)
	{
		totalSort.push_back(rightSort[i]);
	}
	
	return totalSort;
}

int main()
{	
	vector<string> randList;
	srand(time(0));
	fstream f;
	f.open("words.txt");
	string buffer;
	getline(f, buffer);
	int i;
	while(!f.eof())
	{
		randList.push_back(buffer);
		getline(f, buffer);
	}
	f.close();
	
	time_t temp = time(0);
	//printArray(randList);
	printArray(quickSort(randList));
	
	cout << "Quick sort time: " << time(0) - temp << endl;
	
	return 0;
}
 
