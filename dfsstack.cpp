#include <bits/stdc++.h>

using namespace std;

bool visited[100000];
vector <int> adjlist[100000];

void DFS(int s)
{
	int i;
	stack <int> S;
	S.push(s);
	while(!S.empty())
	{
		i=S.top();
		S.pop();
		cout<<i<<endl;
		if(!visited[i])
		{
			visited[i]=true;
			for(auto j : adjlist[i])
			{
				if(!visited[j])
					S.push(j);
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
	for(int i=0;i<n;i++)
		visited[i]=false;
	DFS(0);
	return 0;
}