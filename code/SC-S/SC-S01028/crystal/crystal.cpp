#include<bits/stdc++.h>
#define endl "\n"
#define int long long
using namespace std;
const int N=1e6+9,inf=1e9;
int n,m,a[N],sum[N];
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	int j=1;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		while(j<i && a[i]*(i-j+1)-(sum[i]-sum[j-1])>m)
			j++;
		ans=max(ans,(i-j+1));
	}
	cout<<ans;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T=1;
//	cin>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}