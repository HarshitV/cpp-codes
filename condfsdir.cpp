#include <bits/stdc++.h>

using namespace std;

bool visited[100000];
vector <int> adjlist[100000];
bool visited2[100000];
vector <int> adjlist2[100000];

void dfs(int i)
{
	visited[i]=true;
	cout<<i<<" --> ";

	for(auto j : adjlist[i])
		if(!visited[j])
			dfs(j);
}

void dfs2(int i)
{
	visited2[i]=true;
	cout<<i<<" --> ";

	for(auto j : adjlist2[i])
		if(!visited2[j])
			dfs2(j);
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
	dfs(0);
	cout<<endl;
	dfs2(0);
	int flag=0;
	for(int i=0;i<n;i++)
	{
		if(!visited[i])
		{
			flag=1;
			break;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(!visited2[i])
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
		cout<<"\nNot connected";
	else 
		cout<<"\nConnected";
	return 0;
}