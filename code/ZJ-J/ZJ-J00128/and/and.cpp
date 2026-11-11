#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int a[N];
bool vis[N];
int n, m, ans;
void dfs(int sum, int cnt){
	if(cnt == m){
		ans = max(ans, sum);
		return ;
	}
	for(int i = 1; i <= n; i ++){
		if(vis[i]) continue ;
		vis[i] = true;
		dfs(sum & a[i], cnt + 1);
		vis[i] = false;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	if(m == 1){
		int maxn = -1;
		for(int i = 1; i <= n; i ++){
			maxn = max(maxn, a[i]);
		}
		cout << maxn;
		return 0;
	}
	if(m == n){
		int ans = a[1];
		for(int i = 2; i <= n; i ++){
			ans = ans & a[i];
		}
		cout << ans;
		return 0;
	}
	if(m == 2){
		int ans = 0;
		for(int i = 1; i <= n; i ++){
			for(int j = i + 1; j <= n; j ++){
				ans = max(ans, a[i] & a[j]);
			}
		}
		cout << ans;
		return 0;
	}
	if(n > 2000){
		int maxn = -1;
		for(int i = 1; i <= n; i ++){
			maxn = max(maxn, a[i]);
		}
		if(maxn < 4){
			int s1 = 0, s2 = 0, s3 = 0;
			for(int i = 1; i <= n; i ++){
				if(a[i] == 1) s1 ++;
				else if(a[i] == 2) s2 ++;
				else if(a[i] == 3) s3 ++;
			}
			if(s2 + s3 >= m) cout << 2;
			else if(s1 >= m) cout << 1;
			else cout << 0;
			return 0;
		}
		cout << 0;
		return 0;
	}
	for(int i = 1; i <= n; i ++){
		vis[i] = true;
		dfs(a[i], 1);
		vis[i] = false;
	}
	cout << ans;
	return 0;
}