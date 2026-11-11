#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=5e5+5;
ll n, m, nxt[MAXN], a[MAXN], cnt[MAXN];
vector<int > f[MAXN];
int main() {
	freopen("card.in", "r",stdin);
	freopen("card.out", "w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	memset(nxt, -1, sizeof(nxt));
	for (int i = n; i >= 1; i--) {
		if (nxt[a[i]] != -1) {
			f[i] = f[nxt[a[i]] + 1];
			f[i].push_back(a[i]);
		}
		else nxt[a[i]] = i, f[i] = f[i + 1], f[i].push_back(a[i]);
	}
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < f[i].size(); j++) cnt[f[i][j]]++;
	for (int i = 1; i <= m; i++) cout << cnt[i] << " "; 
	return 0;
}
