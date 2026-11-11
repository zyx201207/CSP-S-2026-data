#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[200005], vis[25], b[25], ans, f1 = 1, maxn;
inline bool check(int x){
	int y = 1;
	if(x == 0) return 1;
	for(int i = 1; i <= 31; i++){
		if(x == y) return 1;
		y = y*2 + 1;
	}return 0;
}
inline void dfs(int x, int res){
	if(x == m + 1){
		ans = max(ans, res);
		return ;
	}for(int i = 1; i <= n; i++){
		if(!vis[i] && b[x - 1] < i){
			vis[i] = 1;
			b[x] = i;
			if(x == 1) dfs(x + 1, a[i]);
			else dfs(x + 1, res&a[i]);
			vis[i] = 0;
		}
	}
}signed main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(check(a[i])) f1 = 0;
		maxn = max(maxn, a[i]);
	}sort(a + 1, a + n + 1);
	if(m == n){
		int res = a[1];
		for(int i = 2; i <= n; i++) res &= a[i];
		cout << res;
		return 0;
	}if(n <= 20) dfs(1, 0);
	if(m == n - 1){
		for(int i = 1; i <= n; i++){
			
		}return 0;
	}if(f1){
		cout << a[n - m + 1];
		return 0;
	}if(maxn <= 4){
		int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
		for(int i = 1; i <= n; i++){
			if(a[i] == 1) s1++;
			if(a[i] == 2) s2++;
			if(a[i] == 3) s3++;
			if(a[i] == 4) s4++;
		}if(s4 >= m) cout << 4;
		else if(s3 >= m) cout << 3;
		else if(s3 + s2 >= m) cout << 2;
		else if(s3 + s2 + s1 >= m) cout << 1;
		else cout << 0;
		return 0;
	}dfs(1, 0);
	cout << ans;
	return 0;
}
