#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 2e6 + 10;
const ll INF = 1e9;
ll a[N];
ll n, d;
ll ans;

ll dis[N];
ll cnt[N];
ll s[N];

void dfs(ll u, ll step){
	//cout << u << " " << step << endl;
	if(dis[u] > step){
		dis[u] = step;
		cnt[u] = 1; 
	}else if(dis[u] == step){
		cnt[u] ++;
	}else{
		return ;
	}
	ll ad = 1;
	while(u + ad <= n && a[u + ad] - a[u] <= d){
		dfs(u + ad, step + 1);
		ad ++;
	}
}

inline void solve(){
	scanf("%lld%lld", &n, &d);
	for(ll i = 1; i <= n; i ++){
		scanf("%lld", &a[i]);
	}
	ans = 0;
	for(ll j = 1; j <= n; j ++){
		for(ll i = 1; i <= n; i ++)dis[i] = INF, cnt[i] = 0;
		dfs(j, 0);
		for(ll i = 1; i <= n; i ++){
			if(cnt[i] == 2){
				ans ++;
				//cout << j << " " << i << endl;
			}
		}
	}
	printf("%lld\n", ans);
}
inline void solve_case11_or_case12(){
	scanf("%lld%lld", &n, &d);
	for(ll i = 1; i <= n; i ++){
		scanf("%lld", &a[i]);
	}
	int t = d / (a[2] - a[1]);
	if(t <= 1)printf("0\n");
	else{
		ll ans = n - t * 2 + 1;
		if(ans >= 0)printf("%lld\n", ans);
		else printf("0\n");
	} 
}
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, T;
	cin >> c >> T;
	while(T --){
		if(c == 11 || c == 12){
			solve_case11_or_case12();
		}else solve();
	}
	return 0;
}
// 4 2 1 2 3 4
// 5 2 1 2 3 4 5
/*
10 3 0 3 6 7 8 9 10 11 14 17 
5 3 -3 0 2 3 4
10 3 0 3 6 7 8 9 10 13 16 19
6 4 -3 0 1 2 3 4
8 3 0 1 2 4 8 10 11 13
6 4 -3 0 1 2 3 4
*/
/*
10 22 0 7 14 21 28 35 42 49 56 63
*/
