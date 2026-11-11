#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;
int c,t,n,k,fa[N];
void solve()
{
	cin>>n>>k;
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
	}
	int p=n/2+1;
	int ans=ceil(1.0*(p-k)/(k+1));
	cout<<ans<<'\n';
	return ;
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
		solve();
	return 0;
}
