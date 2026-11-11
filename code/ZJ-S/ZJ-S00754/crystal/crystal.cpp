#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+10;
ll n,m,a[N],s[N],L,R;
bool check(ll x)
{
	for (ll i = x; i <= n; i++) if (s[i]-s[i-x]+m >= a[i]*x) return 1;
	return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (ll i = 1; i <= n; i++) cin >> a[i];
	sort(a+1,a+n+1);
	for (ll i = 1; i <= n; i++) s[i]=s[i-1]+a[i];
	L=1,R=n;
	while (L <= R)
	{
		ll mid=(L+R)>>1;
		if (check(mid)) L=mid+1;
		else R=mid-1;
	}
	cout << R;
	return 0;
}
// LuoguID: people123
// freopen // freopen // freopen
// zhe dian nao zen me mei you zhong wen shu ru fa
// 噢找到了 
// 666我怎么把自己hack了 
// 哎我去我不会T1 
// q_q我该如何做出T1额
// CCF I love you
// 耶耶T1写好了 15:22
// 电冰箱冰箱冰电，箱冰电电电冰箱，是电冰箱被箱冰电冰，还是箱冰电被电冰箱电 
