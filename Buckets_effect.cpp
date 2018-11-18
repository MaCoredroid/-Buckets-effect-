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
	int max = 0;
	int maxnum = 0;
	for (int i = 0; i < blockvector.size(); i++)
	{
		if (i >= 1)
		{
			if (blockvector[i] >= blockvector[i - 1])
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