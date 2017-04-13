#include <bits/stdc++.h>

using namespace std;

bool visited[100000];
vector <int> adjlist[100000];

void BFS(int src)
{
	queue <int> Q;
	Q.push(src);
	visited[src]=true;
	while(!Q.empty())
	{
		int i=Q.front();
		Q.pop();
		cout<<i<<" --> ";
		for(auto j : adjlist[i])
		{
			if(!visited[j])
			{
				visited[j]=true;
				Q.push(j);
			}
		}
	}
}
int main(void)
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		adjlist[a].push_back(b);
	}
	BFS(0);


	return 0;
}