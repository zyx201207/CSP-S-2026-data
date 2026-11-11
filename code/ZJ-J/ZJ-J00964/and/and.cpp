#include<bits/stdc++.h>
using namespace std;

const int maxn = 200005;

struct node {
	string s;
	int num;
} a[maxn];

long long ans;
int n, m, mxs;
int num[35];
string mp[maxn];
vector<int> could;

bool cmp(node x, node y) {
	return x.s < y.s;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].num;
		int t = a[i].num;
		string s = "";
		while (t) {
			if (t & 1) s += '1';
			else s += '0';
			t >>= 1;
		}
		reverse(s.begin(), s.end());
		a[i].s = s;
		int len = s.size();
		mxs = max(mxs, len);
	}
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n / 2; i++) {
		swap(a[i], a[n - i + 1]);
	}
	for (int i = 1; i <= m; i++) {
		if (i == 1) {
			ans = a[i].num;
		} else {
			ans &= a[i].num;
		}
	}
	cout << ans << endl;
	return 0;
}