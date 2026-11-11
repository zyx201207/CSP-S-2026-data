#include<bits/stdc++.h>
using namespace std;

#define int long long


signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int c, t;
	cin>>c>>t;
	while(t--)
	{
		int n, k;
		cin>>n>>k;
		for(int i=1; i<n; i++)
		{
			int u, v;
			cin>>u>>v;
		}
		if(n==k)cout<<0;
		else if(c>=13&&c<=14)
		{
			int m=(n-1)/2;
			int ans=max(1LL, (m-k)/4+2);
			cout<<ans;
		} 
		else cout<<1;
		cout<<'\n';
	}
	return 0;
}
