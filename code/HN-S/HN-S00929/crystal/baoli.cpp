#include<bits/stdc++.h>
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define __low lower_bound
#define __upp upper_bound
#define pii pair<int,int>
#define MP make_pair
#define fi first
#define se second
#define ls (p << 1)
#define rs (p << 1 | 1)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int N = 5e5+5;

int n, m;
ll a[N];
ll ans;

bool vis[N];

void check(){
	ll sum1 = 0, sum2 = 0, maxx = 0;
	for(int i = 1; i <= n; i++){
		if(vis[i]){
			maxx = max(maxx, a[i]);
			sum1++, sum2 += a[i];
		} 
	}
	if(maxx * sum1 - sum2 <= m) ans = max(ans, sum1);
}

void dfs(int x){
	if(x > n){
		check();
		return;
	}
	vis[x] = 1;
	dfs(x+1);
	vis[x] = 0;
	dfs(x+1);
}

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("baoli.out", "w", stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	dfs(1);
	cout << ans << "\n";
	
	return 0;
} 
