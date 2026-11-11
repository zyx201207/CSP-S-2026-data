#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[200001];
int ans = 0;
int n, m;
map<int, int>mp;

struct node {
	int v, sum;
} b[200001];

bool cmp(node x, node y) {
	if (x.sum == y.sum) {
		return x.v > y.v;
	} else {
		return x.sum > y.sum;
	}
}

signed main() {
	freopen("and.in", "r", "stdin");
	freopen("and.out", "w", "stdout");
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		mp[a[i]]++;
	}
	int l = 1;
	for (auto i : mp) {
		b[l].v = i.first;
		b[l].sum = i.second;
		l++;
	}
	sort(b + 1, b + 1 + n, cmp);
	int num = 0, ans = b[1].v;
	int i = 1;
	while (num < m) {
		for (int j = 1; j <= b[i].sum; ++j) {
			ans = ans & b[i].v;
			num++;
			if (num == m) {
				break;
			}
		}
		++i;
	}
	cout << ans;
	return 0;
}