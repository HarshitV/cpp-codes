#include <bits/stdc++.h>

using namespace std;

vector <int> adjlist[100000];
bool visited[100000];

void bfs(int src)
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
	int m,n,a,b,i;
	cin>>n>>m;
	for(i=0;i<m;i++)
	{
		cin>>a>>b;
		adjlist[a].push_back(b);
		adjlist[b].push_back(a);
	}
	bfs(0);
	return 0;
}