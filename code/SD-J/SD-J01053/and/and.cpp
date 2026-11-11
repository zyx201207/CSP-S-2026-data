#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
ll a[200005];
ll ans;
int f[200005];

inline void dfs(int x, int y)
{
	if(y == m && x == n + 1)
	{
		ll s = 0;
		for(int i = 1; i <= x; i++)
			if(f[i] == 1) {
				s = a[i];
				break;
			}
		for(int i = 1; i <= x; i++)
			if(f[i] == 1){
				s = s & a[i];
			}
		ans = ans > s ? ans : s;
		return;
	}	
	if(x > n)
		return;
	f[x] = 1;
	dfs(x + 1, y + 1);	
	f[x] = 0;
	dfs(x + 1, y);
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	if(m == 1) {
		ll s = 0;
		for(int i = 1; i <= n; i++)
			s = s > a[i] ? s : a[i];
	} else if(m == n) {
		ll s = a[1];
		for(int i = 1; i <= n; i++)
			s = s & a[i];
		printf("%lld\n", s);
	} else if(m == 2) {
		sort(a + 1, a + n + 1);
		ll s = 0;
		for(int i = n; i >= 2; i--)
			s = s > a[i] & a[i - 1] ? s : a[i] & a[i - 1];
		printf("%lld\n", s);
	}else if(m == n - 1) {
		ll l[200005], r[200005];
		l[0] = a[1];
		for(int i = 1; i <= n; i++)
			l[i] = l[i - 1] & a[i];
		r[n + 1] = a[n];
		for(int i = n; i >= 1; i--)
			r[i] = r[i + 1] & a[i];
		ll s = l[n - 1] > r[2] ? l[n - 1] : r[2];
		for(int i = 2; i <= n; i++)
			s = s > l[i - 1] & r[i + 1] ?  s : l[i - 1] & r[i + 1];
	} else {
		dfs(1,0);
		printf("%lld\n", ans);
	}
	return 0;
} 



/*
                                                                                                                                                                                                                                                                                       
                                                                                                                                                   
*/ 
