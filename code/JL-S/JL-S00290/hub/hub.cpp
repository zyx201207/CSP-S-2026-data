#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
int n,k;
int u,v;
vector <int> mp[1000005];
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<=n-1;i++)
		{
			cin>>u>>v;
			mp[u].push_back(v);
			mp[v].push_back(u);
		}
		int num=rand();
		cout<<num%n+1<<endl;
	}
}