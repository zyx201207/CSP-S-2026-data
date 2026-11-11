#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+10;
ll n,m,a[N],x,cnt;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (ll i = 1; i <= n; i++) cin >> a[i];
	x=0;
	for (ll i = 30; i >= 0; i--)
	{
		x+=(1<<i),cnt=0;
		for (ll j = 1; j <= n; j++) if ((a[j]&x) == x) cnt++;
		if (cnt < m) x-=(1<<i);
	}
	cout << x;
	return 0;
}
// Ah?? I can do T3 but I can't do T2? q_q
// luogu: @people123
