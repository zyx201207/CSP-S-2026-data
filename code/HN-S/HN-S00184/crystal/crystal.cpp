#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=5e5+5;
int n,ans;
ll m,a[M];
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	ll tmp=0;
	int now=1; 
	for(int i=1;i<=n;i++)
	{
		tmp+=a[i];
		for(;now<=i&&(ll)(i-now+1)*a[i]-tmp>m;tmp-=a[now++]){}
		ans=max(ans,i-now+1);
	}
	cout<<ans;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--)
		solve();
	return 0;
}
