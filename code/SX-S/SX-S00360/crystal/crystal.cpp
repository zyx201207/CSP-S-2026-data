#include <bits/stdc++.h>
using namespace std;

deque<int>qwq;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n = 0, m = 0;
	vector<int> v;
	v.push_back(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int aaa;
		cin >> aaa;
		v.push_back(aaa);
	}
	sort(v.begin(), v.end());
	int qqq = 0;
	for (int i = 1; i < n; i++) {
		qqq += v[n] - v[i];
	}
	qwq.push_back(qqq);
	for (int i = n - 1; i >= 1; i--) {

		for (int o = i; o < n; o++) {
			if (o == i) {
				qwq.push_back(qwq.front() - (v[o + 1] - v[o]) * i);
			}
			int qpq = qwq.front();
			int qcq = qpq - v[o + 1] + v[o - i + 1];
			qwq.push_back(qcq);
			if (qwq.front() <= m) {
				cout << i + 1;
				return 0;
			}
			qwq.pop_front();
		}
	}

	return 0;
}
