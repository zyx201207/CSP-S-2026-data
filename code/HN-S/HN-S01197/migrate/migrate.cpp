#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e6 + 5;

int c, t, n, d, a[N], dis[N], cnt[N];

int F(int x){
	if(x <= 0){
		return 0;
	}
	return upper_bound(a + 1, a + n + 1, a[x] + d) - a - 1;
}

void Work(){
	int ans = 0;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			dis[j] = -1;
			cnt[j] = 0;
		}
		queue<int> q;
		q.push(i);
		dis[i] = 0;
		cnt[i] = 1;
		while(!q.empty()){
			int u = q.front();
			q.pop();
			for(int j = 1; j <= n; ++j){
				if(abs(a[u] - a[j]) > d){
					continue;
				}
//				cout << u << ' ' << j << ' ' << dis[u] + 1 << ' ' << dis[j] << '\n';
				if(dis[j] == -1){
					dis[j] = dis[u] + 1;
					cnt[j] = cnt[u];
					q.push(j);
				}else if(dis[u] + 1 == dis[j]){
					cnt[j] += cnt[u]; 
				}
			}
		}
		for(int j = i + 1; j <= n; ++j){
			if(cnt[j] == 2){
				ans++;
			}
		}
	}
	cout << ans << '\n';
}

void Solve(){
	cin >> n >> d;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
	}
	if(n <= 300){
		Work();
		return;
	}
	int ans = 0;
	for(int i = 1; i <= n; ++i){
		int x = F(i);
		int c1 = 1, c2 = 1;
		for(int r = x; F(r) != r && r < n; r = F(r)){
			if(c1 == 1 && c2 == 1){
				if(F(r - 1) > r){
					ans += F(r - 1) - max(r, F(r - 2));
				}
			}else if(c2 == 2){
				ans += F(r) - max(r, F(r - 1));
			}else if(c2 == 1){
				continue;
			}else{
				break;
			}
			if(F(r - 1) >= F(r)){
				c2 += c1;
			}
			if(F(r - 2) >= F(r)){
				c2++;
			}
			if(F(r - 2) >= F(r) - 1){
				c1++;
			}
		}
//		cout << i << ' ' << ans << '\n';
	}
	cout << ans << '\n';
}

signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> c >> t;
	while(t--){
		Solve();
	}
	return 0;
}

