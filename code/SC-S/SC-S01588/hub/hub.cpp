//cornhub
#include<bits/stdc++.h>
using namespace std;
const int N=4e6+5;
int c,t,n,k;
vector<int>g[N];
main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		g[n].clear();
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout<<"关注塔菲喵\n";
	}
	return 0;
}