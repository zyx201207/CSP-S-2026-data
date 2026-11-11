#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<=n-1;i++)
		{
			int u,v;
			cin>>u>>v;
		}
		cout<<k-1<<"\n";
	}
	return 0;
}
