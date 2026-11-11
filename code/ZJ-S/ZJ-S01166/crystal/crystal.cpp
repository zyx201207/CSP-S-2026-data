#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e6+10;


ll tt = 1,ans = 0,n,a[MAXN],b[MAXN],m,sum,pj,cf[MAXN],pr[MAXN];


int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(ll i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	for(ll i=1;i<=n;i++)
	{
		cf[i] = a[i] - a[i-1];
		pr[i] = pr[i-1] + a[i];
	}
	for(int i=1;i<=n;i++)
	{
		ll su = pr[i-1] - pr[tt-1];
		ll ss = i-tt;
		while(a[i] * ss - su > m && tt <= i)
		{
			tt++;
			su = pr[i-1] - pr[tt-1];
			ss = i-tt;
		}
		ans = max(ans,ss+1);
	}
	cout << ans;
	return 0;
}
