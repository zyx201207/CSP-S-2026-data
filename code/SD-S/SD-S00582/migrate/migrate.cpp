#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e6 + 5;
int n, d, sum, a[N], mn = 0x3f3f3f3f;
bool flag;
void dfs(int l, int r, int cnt){
	if(flag)return;
	if(l == r && cnt == mn)sum++;
	if(sum > 2)flag = true;
	for(int i = l + 1; i <= r && a[i] - a[l] <= d; i++){
		dfs(i, r, cnt + 1);
	}
}
void f(int l, int r, int cnt){
	if(l == r)mn = min(mn, cnt);
	for(int i = l + 1; i <= r && a[i] - a[l] <= d; i++){
		f(i, r, cnt + 1);
	}
}

signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int c, t;
	cin >> c >> t;
	while(t--){
		int ans = 0;
		cin >> n >> d;
		for(int i = 1; i <= n; i++)cin >> a[i];
		for(int i = 1; i <= n; i++){
			for(int j = i + 2; j <= n; j++){
				sum = 0, flag = false, mn = 0x3f3f3f3f;
				f(i, j, 0);
				dfs(i, j, 0);
				if(sum == 2){
					ans++;
				}
			}
		}
		cout << ans << '\n'; 
	}
	return 0;
}
