#include <bits/stdc++.h>
using namespace std;
int n;
int to[30];

struct node {
	long long sum;
	char a;
};
stack<node> l;
queue<node> r;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	node mid;

	for (int i = 1; i <= n; i++) {

		long long x;
		char a;
		cin >> x >> a;

		if (i < (n + 1) / 2) {
			l.push({x, a});
		} else if (i > (n + 1) / 2) {
			r.push({x, a});
		} else {
			mid = {x, a};
		}

		to[int(a - 64)]++;

		if (to[int(a - 64)] == n) {
			cout << 0;
			return 0;
		}
	}

	if (l.size() > r.size()) {
		r.push({0, '0'});
	}

	long long ans = 0;

	while (!r.empty()) {
		node lt;

		if (l.empty()) {
			lt = {0, '0'};
		} else {
			lt = l.top();
		}

		l.pop();
		node rt = r.front();
		r.pop();

		if (lt.sum == rt.sum && lt.a == rt.a) {
			continue;
		} else if (lt.sum == rt.sum && lt.a != rt.a) {
			ans += lt.sum;
		} else if (lt.sum != rt.sum && lt.a == rt.a) {
			ans += abs(lt.sum - rt.sum);
		} else {
			ans += max(lt.sum, rt.sum);
		}
	}

	cout << ans;
	return 0;
}
