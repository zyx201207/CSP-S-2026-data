#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
int c,t,n,m,k;

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>m>>k;
		for(int i = 1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			vector<vector<int>> trie(n+1);
			trie[u].push_back(v);
			trie[v].push_back(u);
		}
	}
	return 0;
}
