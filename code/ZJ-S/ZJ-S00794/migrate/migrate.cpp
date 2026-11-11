#include<bits/stdc++.h>
#define ll long long
using namespace std;
constexpr int N = 2000001;
int kkksc03, T, n, d, a[N], ans, min_st;
int dfs(int id, int r, int step){
	if(step > min_st) return 0;
	if(id == r){
		if(step == min_st) return 1;
		else return 0;
	}
	int res = 0;
	for(int i = id + 1; i <= n; i++){
		if(a[i] - a[id] > d) break;
		res += dfs(i, r, step + 1);
	}
	return res;
}
void dfs1(int id, int r, int step){
	if(step > min_st) return;
	if(id == r){
		min_st = min(min_st, step);
		return;
	}
	int res = 0;
	for(int i = id + 1; i <= n; i++){
		if(a[i] - a[id] > d) break;
		dfs1(i, r, step + 1);
	}
}
bool check(int l, int r){
	min_st = INT_MAX;
	dfs1(l, r, 0);
//	cout << min_st << ' ';
	return dfs(l, r, 0) == 2;
}
void solve(){
	cin >> n >> d;
	ans = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j++){
			if(check(i, j)){
				ans++;
//				cout << i << ' ' << j << '\n';
			}
		}
	}
	cout << ans << '\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> kkksc03 >> T;
	while(T--) solve();
	return 0;
}
