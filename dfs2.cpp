#include <bits/stdc++.h>

using namespace std;

vector <int> adjlist[100000];
bool visited[100000];
void DFS(int i)
{
	cout<<i<<" --> ";
	visited[i]=true;
	for(auto j : adjlist[i])
		if(!visited[j])
			DFS(j);
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
	DFS(0);





	return 0;
}
