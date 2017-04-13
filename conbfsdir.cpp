#include <bits/stdc++.h>

using namespace std;

bool visited[100000];
bool visited2[100000];
vector <int> adjlist2[100000];
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


void BFS2(int src)
{
	queue <int> Q;
	Q.push(src);
	visited2[src]=true;
	cout<<endl;
	while(!Q.empty())
	{
		int i=Q.front();
		Q.pop();
		cout<<i<<" --> ";
		for(auto j : adjlist2[i])
		{
			if(!visited2[j])
			{
				visited2[j]=true;
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
		adjlist2[b].push_back(a);
	}
	BFS(0);
	BFS2(0);
	int flag=0;
	for(int i=0;i<n;i++)
	{
		if(visited[i]==0)
		{
			flag=1;
			break;
		}

	}
	for(int i=0;i<n;i++)
	{
		if(visited2[i]==0)
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