#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pii pair<int,int>
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,k;
		
		cin>>n>>k;
		int ans=9191917878;
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			ans=min(ans,abs(u-v));
		}
		cout<<ans<<endl;
	}
	return 0;
}
