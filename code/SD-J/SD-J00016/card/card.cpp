#include<iostream>
#include<algorithm>
#include<cmath>
#include<bitset>
#include<vector>
using namespace std;
#define ll long long
#define endl '\n'
#define pii pair<int, int>
const int N = 5e5 + 5;
vector<int> e[N];
int cnt[N], a[N], l[N], siz[N];
void dfs(int u) {
	siz[u] = 1;
	for(auto v : e[u]) {
		dfs(v);
		siz[u] += siz[v];
	}
	cnt[a[u]] = max(cnt[a[u]], siz[u]);
	return ;
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m; cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
		
	l[a[n]] = n;
	for(int i = n-1; i >= 1; i--) {
		if(!l[a[i]]) e[i+1].push_back(i);
		else e[l[a[i]]].push_back(i);
		l[a[i]] = i;
	}
	dfs(n);
	
	for(int i = 1; i <= m; i++)
		cout << cnt[i] << ' ';
	return 0;
}

