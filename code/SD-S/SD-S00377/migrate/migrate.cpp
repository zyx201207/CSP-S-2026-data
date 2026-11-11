#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5,inf=0x3f3f3f3f3f3f3f3f,eps=1e-8;
int a[N];
void solve()
{
	int n,d;cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>a[i];
	int w=a[2]-a[1];
	int ci=d/w;
	ci+=(ci-1);
	if(ci<2) cout<<0<<'\n';
	else cout<<max(n-ci,0ll)<<'\n';
	return ;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c,t;cin>>c>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}

