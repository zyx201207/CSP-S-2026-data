#include <bits/stdc++.h>
using namespace std;

int n, m, a[200001], ans[5001];
bool f[5001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) {
		memset(f,0,sizeof f);
		vector<int> v;
		for(int j = i; j <= n; j++) {
			if(f[a[j]]) {
				int p;
				for(int k = 0; i < v.size(); i++) {
					if(v[k] == a[i]) {
						p = k;
						break;
					}
				}
				for(;p < v.size();p++) {
					v[p] = -1;
				}
				f[a[j]] = 0;
			}
			v.push_back(a[j]);
			f[a[j]] = 1;
		}
		for(int j = 0; j <v.size(); ++j) ans[v[j]]++;
	}
	for(int i = 1; i <= m; i++) cout << ans[i] << " ";
	return 0;
}

