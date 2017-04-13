#include <bits/stdc++.h>

using namespace std;

bool visited[100000];
vector <int> alist[100000];

void DFS(int i)
{
	cout<<i<<" --> ";
	visited[i]=true;

	for(int j : alist[i])
	{
		if(!visited[j])
		{
			DFS(j);
		}
	}
}






int main(void)
{
	int n,m,a,b,i;
	cin>>n>>m;
	for(i=0;i<m;i++)
	{
		cin>>a>>b;
		alist[a].push_back(b);
		alist[b].push_back(a);
	}
	DFS(1);
	return 0;
}