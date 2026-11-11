#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
const int N = 2e5 + 3;
int n, sum[N], ans;
struct Node {
	int len;
	char c;
	friend istream &operator >> (istream &is, Node &t) {
		is >> t.len >> t.c;
		return is;
	}
} a[N];
deque<Node> vec[2];

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i].len;
	}
	int mid = sum[n] / 2;
	for (int i = 1; i <= n && mid; i++) {
		if (a[i].len <= mid) {
			vec[0].push_back(a[i]);
			mid -= a[i].len;
		} else {
			Node b = {mid, a[i].c};
			vec[0].push_back(b);
			break;
		}
	}
	mid = sum[n] / 2;
	for (int i = n; i >= 1 && mid; i--) {
		if (a[i].len <= mid) {
			vec[1].push_back(a[i]);
			mid -= a[i].len;
		} else {
			Node b = {mid, a[i].c};
			vec[1].push_back(b);
			break;
		}
	}
	while (!vec[0].empty() && !vec[1].empty()) {
		int minn = min(vec[0].front().len, vec[1].front().len);
		vec[0].front().len -= minn, vec[1].front().len -= minn;
		ans += minn * (vec[0].front().c != vec[1].front().c);
		if (vec[0].front().len == 0) vec[0].pop_front();
		if (vec[1].front().len == 0) vec[1].pop_front();
	}
	cout << ans;
	
	return 0;
}
