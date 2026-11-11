#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e6 + 10;
int c, t, n, id, id2, f[N];
ll d, x[N], f2[N], ans;
bool vis[N];
vector<int> g[N];
queue<int> q;
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		bool fl1 = false;
		for(int i = 1; i <= n; i++) g[i].clear();
		ans = 0;
		for(int i = 1; i <= n; i++) cin >> x[i];
		if(n <= 3){
			cout << 0 << '\n';
			continue;
		}
		if(n <= 5000){
			for(int i = 1; i <= n; i++){
				int l = i, r = n, a1 = i;
				while(l <= r){
					int mid = l + r >> 1;
					if(x[mid] - x[i] <= d) l = mid + 1, a1 = mid;
					else r = mid - 1;
				}
				for(int j = i + 1; j <= a1; j++) g[i].push_back(j);
			}
			for(int i = 1; i <= n; i++){
				q.push(i);
				f2[i] = 1;
				while(q.size()){
					int u = q.front();
					q.pop();
					for(auto p : g[u]){
						if(!vis[p]) f[p] = f[u] + 1, f2[p] = f2[u], vis[p] = 1, q.push(p);
						else if(f[p] == f[u] + 1) f2[p] += f2[u];
					}
				}
				for(int j = i + 1; j <= n; j++){
					if(f2[j] == 2){
						ans++;
					}
				}
				for(int j = i; j <= n; j++) vis[j] = 0, f[j] = 0, f2[j] = 0;
			}
			cout << ans << '\n';
			continue;
		}
		id = 0, id2 = 0;
		for(int i = 1; i <= n; i++){
			if(x[i] - x[1] <= d && x[n] - x[i] <= d) fl1 = true, id = (id == 0 ? i : id), id2 = i;
		}
		if(fl1){
			if(id2 != id && id2 - id > 1){
				cout << 0 << '\n';
				continue;
			}else if(id2 != id){
				cout << n - id2 << '\n';
				continue;
			}
			int l = id - 1, r = n, a1 = id - 1, mx1 = 0, mx2 = 0;
			while(l <= r){
				int mid = l + r >> 1;
				if(x[mid] - x[id - 1] <= d) l = mid + 1, a1 = mid;
				else r = mid - 1;
			}
			mx1 = a1;
			if(id - 2 > 0){
				l = id - 2, r = n, a1 = id - 2;
				while(l <= r){
					int mid = l + r >> 1;
					if(x[mid] - x[id - 2] <= d) l = mid + 1, a1 = mid;
					else r = mid - 1;
				}
				mx2 = a1;
			}
			for(int i = 1; i < id; i++){
				l = i, r = n, a1 = i;
				while(l <= r){
					int mid = l + r >> 1;
					if(x[mid] - x[i] <= d) l = mid + 1, a1 = mid;
					else r = mid - 1;
				}
				if(a1 == id + 1){
					l = id + 1, r = n, a1 = id + 1;
					while(l <= r){
						int mid = l + r >> 1;
						if(x[mid] - x[id + 1] <= d) l = mid + 1, a1 = mid;
						else r = mid - 1;
					}
					ans += a1 - mx1 + 1;
				}else if(a1 == id - 1){
					l = id - 1, r = n, a1 = id - 1;
					while(l <= r){
						int mid = l + r >> 1;
						if(x[mid] - x[id - 1] <= d) l = mid + 1, a1 = mid;
						else r = mid - 1;
					}
					if(mx2 != 0) ans += a1 - mx2 + 1;
				}
			}
			cout << ans << '\n';
			continue;
		}
		cout << (ll)(n * (n - 1)) / 2 << '\n';
	}
	return 0;
}
