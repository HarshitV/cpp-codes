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
		adjlist[b].push_back(a);
	}
	BFS(0);
	int flag=0;
	for(int i=0;i<n;i++)
	{
		if(visited[i]==0)
		{
			flag=1;
			break;
		}

	}
	if(flag==1)
		cout<<"\nnot connected";
	else 
		cout<<"\nConnected";
	return 0;
}