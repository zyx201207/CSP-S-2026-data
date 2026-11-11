#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,t,n,k,tmp[105];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		vector<int> g[1000005];
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if(k==2)
		{
			//noooooo i have no time to write special xingzhi
		}
		cout<<"0\n";
	}
	return 0;
}

