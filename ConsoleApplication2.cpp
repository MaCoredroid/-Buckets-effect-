// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <vector>
#include <string>

void input(std::string& blocks)
{
	
	std::cin >> blocks;
	
}

void calculate(std::vector<int>& blockvector,std::string& blocks,int& water)
{

	for (int i = 0; i < blocks.size(); i++)
	{
		if (blocks[i] == ',')
		{
			continue;
		}
		else
		{
			blockvector.push_back(int(blocks[i]));
		}
	}
	int max = 0;// the max height before the current one
	int maxnum = 0;//the number of max height
	for (int i = 0; i < blockvector.size(); i++)
	{
		if (i >= 1)
		{
			if (blockvector[i] >= blockvector[i - 1])//count water and fix the height
			{
				if (blockvector[i] >= max)
				{
					for (int j = maxnum+1; j < i; j++)
					{
						if (max - blockvector[j] > 0)
						{
							water += max - blockvector[j];
							blockvector[j] = max;
						}
					}
				}
				else
				{
					for (int j = maxnum+1; j < i; j++)
					{
						if (blockvector[i] - blockvector[j] > 0)
						{
							water += blockvector[i] - blockvector[j];
							blockvector[j] = blockvector[i];
						}
					}
				}
			}
			else
			{
				continue;
			}
		}
		if (blockvector[i] >= max)
		{
			max = blockvector[i];
			maxnum = i;
		}
	}
}
int main()
{
	std::vector<int> blockvector;
	std::string blocks="";
	int water = 0;
    input(blocks);
	calculate(blockvector, blocks, water);
    std:: cout << water;
	
	
}




// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
