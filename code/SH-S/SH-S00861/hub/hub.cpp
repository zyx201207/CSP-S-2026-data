#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int dp[N];
vector g[N];


int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		intu,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	
	return 0;
}
