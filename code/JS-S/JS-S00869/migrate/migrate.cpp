#include <bits/stdc++.h>
#define int long long
using namespace std;
int c, t, n, d, a[2000010], cnt[2000010], dis[2000010], k[2000010];
vector<pair<int, int> > g[2000010];
deque<int> q;
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	if (c == 11 || c == 12){
		while (t--){
			cin >> n >> d;
			for (int i=1; i<=n; i++)
				cin >> a[i];
			if (n == 1){
				cout << 0 << '\n';
				continue;
			}
			int ans=0, cnt=d/(a[2]-a[1]);
			if (cnt <= 1){
				cout << 0 << '\n';
				continue;
			}
			for (int i=1; i<=n; i++)
				if (n - i + 1 >= cnt * 2)
					++ans;
			cout << ans << '\n';
		}
		return 0;
	}
	if (c == 13 || c == 14){
		while (t--){
			cin >> n >> d;
			for (int i=1; i<=n; i++)
				cin >> a[i];
			for (int i=n, j=n; i>=1; i--){
				j = min(j, i);
				while (j > 1 && a[i] - a[j-1] <= d)
					--j;
				k[i] = j;
			}
			int ans=0, j=1, t=0;
			for (int i=1; i<=n; i++){
				j = max(j, i);
				while (j < n && a[j+1] - a[i] <= d)
					++j;
				if (j == i)
					continue;
				t = max(t, j-1);
				while (t < n && a[t+1] - a[j-1] <= d)
					++t;
				if (k[t] == j - 1)
					++ans;
			}
			cout << ans << '\n';
		}
		return 0;
	}
	while (t--){
		cin >> n >> d;
		for (int i=1; i<=n; i++){
			cin >> a[i];
			g[i].clear();
		}
		int ans=0;
		for (int i=1, j=1; i<=n; i=j+1){
			j = max(j, i);
			while (j < n && a[j+1] - a[j] <= d)
				++j;
			for (int l=i, r=i; l<=j; l++){
				while (r < n && a[r+1] - a[l] <= d)
					++r;
				g[l].push_back({r, 1});
			}
			for (int t=i; t<j; t++)
				g[t+1].push_back({t, 0});
			for (int t=i; t<=j; t++){
				for (int l=i; l<=j; l++){
					cnt[l] = 0;
					dis[l] = 1e18;
				}
				q.clear();
				q.push_back(t);
				dis[t] = 0;
				cnt[t] = 1;
				while (q.size()){
					int u=q.front();
					q.pop_front();
					for (auto it : g[u]){
						if (it.first < t)
							continue;
						if (it.second == 0){
							if (dis[it.first] > dis[u]){
								dis[it.first] = dis[u];
								cnt[it.first] = cnt[u];
								q.push_front(it.first);
							}
							else if (dis[it.first] == dis[u])
								cnt[it.first] += cnt[u];
						}
						else{
							if (dis[it.first] > dis[u] + 1){
								dis[it.first] = dis[u] + 1;
								cnt[it.first] = cnt[u];
								q.push_back(it.first);
							}
							else if (dis[it.first] == dis[u] + 1)
								cnt[it.first] += cnt[u];
						}
					}
				}
				for (int l=t+1; l<=j; l++)
					ans += (cnt[l] == 2);
			}
		}
		cout << ans << '\n';
	}
}