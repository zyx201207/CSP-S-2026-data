#include <bits/stdc++.h>
using namespace std;

struct node {
	bool f;
	int k;
};
int n, m, a[500005], ans[300005];
map<int, node>vis;
vector<int>v;

bool find(int k) {
	for (int i : v)
		if (i == k)
			return  true;
	return false;
}

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) {
		vis.clear();
		v.clear();
		for (int j = i; j <= n; j++) {
			if (vis[a[j]].f && find(a[j])) {
				v.erase(v.begin() + vis[a[j]].k - 1, v.begin() + v.size());
				v.push_back(a[j]);
				vis[a[j]].k = v.size();

			} else {
				v.push_back(a[j]);
				vis[a[j]] = {true, v.size()};
			}
		}
		for (int i = 0; i < v.size(); i++)
			ans[v[i]]++;
	}
	for (int i = 1; i <= m; i++)
		printf("%d ", ans[i]);
	return 0;
}