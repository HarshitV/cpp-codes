#include <bits/stdc++.h>

using namespace std;

bool visited[100000];
vector <int> adjlist[100000];
bool visited2[100000];
vector <int> adjlist2[100000];
int t=-1;
int finish[100000];
int order[100000];

void DFS(int s)
{
	int i
	;while(!S.empty())
	{
		i=S.top();
		S.pop();
		// cout<<i<<endl;
		if(!visited[i])
		{
			visited[i]=true;
			for(auto j : adjlist[i])
			{
				if(!visited[j])
					S.push(j);
			}
		}
		t++;
		finish[i]=t;
		order[finish[i]]=i;
	}
}

void DFS2(int i)
{
	cout<<i<<" --> ";
	visited2[i]=true;
	for (auto j : adjlist2[i])
	{
		if(!visited2[j])
			DFS2(j);
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
	for(int i=0;i<n;i++)
		visited[i]=false;
	for(int i=0;i<n;i++)
		visited2[i]=false;
	DFS(0);
	for(int i=0;i<n;i++)
		cout<<i<<" "<<finish[i]<<endl;
	cout<<"\nSCC"<<endl;
	for(int i=0;i<=n-1;i++)
	{
		if(!visited2[order[i]])
		{
			DFS2(order[i]);
			cout<<endl;
		}
	}
	//DFS2(0);
	return 0;
}