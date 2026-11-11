#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 500005;
int n;
ll m;
ll a[maxn];

ll ans = 0;
ll check(ll target){
	ll t = 0, cnt1 = 0;
	for(int i = n; i >= 1; --i)
	{
		if(target >= a[i])
		{
			t += target - a[i];
			if(t <= m)++cnt1;
		}
	}
	ans = max(ans, cnt1);
	return t;
}
void binary_search(ll l, ll r){
	while(l < r)
	{
		ll mid = l + (r - l) / 2;
		ll cnt = check(mid);
		if(cnt > m)r = mid;
		if(cnt == m)return;
		if(cnt < m)l = mid + 1;
	}
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%lld", &a[i]);
	}
	sort(a+1, a+n+1);
	binary_search(a[1], a[n]+m);
	printf("%lld", ans);
	return 0;
} 