#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;
set < vector < int >> visited;
void dfs (vector < int > node)
{
	visited.insert(node);
	cout << node[0] << " " << node[1] << " "  << node[2]  << endl;
	for(int  i=0;i < 3;i++)
	{
		int max;
		for (int j=0; j<3;j++)
		{
			if(j == 0) max = 10;
			else if (j==1) max =7;
			else max=4;
			if (i != j && node[i] > 0 && node[j] < max	)
			{
				int diff = min(node[i],max - node[j]);
				vector<int> next_node[3];
				next_node[i] = node[i] - diff;
				next_node[j] = node[j] + diff;
				next_node[3 - i - j] = node[3-i-j];
				if (visited.find(next_node) == visited.end()) dfs(next_node);					
			}
			}
		}
	}
int main()
{
	dfs({0,7,4});
	return 0;
}
