#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200001], pre[200001], num[200001], f[11], maxn = 0, n, m;
void bfs(int v, int id, int step){
	if(step == m){
		maxn = max(maxn, v);
		return;
	}else if(id > n && step < m){
		return;
	}
	for(int i = id+1; i <= n; i++){
		bfs(v&a[i], i, step+1);
	}
	return;
}
int cmp(int x, int y){
	return x > y;
}
signed main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	if(n <= 20){
		for(int i = 1; i <= n; i++){
			bfs(a[i], i, 1);
		}
		cout << maxn;
		return 0;
	}else if(n > 20 && n <= 2000){
		if(m == 1){
			for(int i = 1; i <= n; i++){
				maxn = max(maxn, a[i]);
			}
			cout << maxn;
			return 0;
		}else if(m == n){
			int ans = LLONG_MAX;
			for(int i = 1; i <= n; i++){
				ans &= a[i];
			}
			cout << ans;
			return 0;
		}else if(m == 2){
			for(int i = 1; i < n; i++){
				for(int j = i+1; j <= n; j++){
					maxn = max(maxn, a[i]&a[j]);
				}
			}
			cout << maxn;
			return 0;
		}
	}else if(n > 2000 && n <= 200000){
		if(m == n-1){
			pre[0] = LLONG_MAX;
			for(int i = 1; i <= n; i++){
				pre[i] = pre[i-1]&a[i];
			}
			num[n+1] = LLONG_MAX;
			for(int i = n; i >= 1; i--){
				num[i] = num[i+1]&a[i];
			}
			for(int i = 1; i <= n; i++){
				maxn = max(maxn, pre[i-1]&num[i+1]);
			}
			cout << maxn;
			return 0;
		}
		int maxx = 0;
		for(int i = 1; i <= n; i++){
			maxx = max(maxx, a[i]);
		}
		if(maxx == 4){
			for(int i = 1; i <= n; i++){
				f[a[i]]++;
			}
			if(f[4] >= m){
				cout << 4;
			}else if(f[3] >= m){
				cout << 3;
			}else if(f[3]+f[2] >= m){
				cout << 2;
			}else if(f[3]+f[1] >= m){
				cout << 1;
			}else{
				cout << 0;
			}
			return 0;
		}
		sort(a+1, a+n+1, cmp);
		int ans = LLONG_MAX;
		for(int i = 1; i <= m; i++){
			ans &= a[i];
		}
		cout << ans;
	}
	return 0;
}
