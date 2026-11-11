#include <bits/stdc++.h>
using namespace std;
int n, m;
long ma, a[100005];
deque<long>e;

long z() {
	long q = e.front();
	for (int i = 0; i < m; i++) {
		//cout << e.front() << '-';
		q &= e.front();
		e.push_back(e.front());
		e.pop_front();
	}
	return q;
}

void fs(int q, int w) {
	if (w >= m) {
		//cout << z() << '&';
		ma = max(ma, z());
		//cout << z() << '|';
		return;
	} else
		for (int i = q + 1; i < n; i++) {
			e.push_back(a[i]);
			fs(i, w + 1);
			e.pop_back();
		}
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	fs(-1, 0);
	cout << ma;
	return 0;
}