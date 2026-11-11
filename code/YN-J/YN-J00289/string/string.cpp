#include <bits/stdc++.h>
using namespace std;
deque<pair<long long, char>>dq;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	long long ans = 0;

	for (int i = 1; i <= n; i++) {

		pair<long long, char>a;
		cin >> a.first >> a.second;

		if (dq.size() && dq.back().second == a.second) {
			a.first += dq.back().first;
			dq.pop_back();
		}

		dq.push_back(a);
	}

	while (dq.size() > 1) {
		char c1 = dq.front().second, c2 = dq.back().second;
		long long num1 = dq.front().first, num2 = dq.back().first;
		//	cout << c1 << ' ' << c2 << ' ' << num1 << ' ' << num2 << '\n';

		if (c1 == c2) {
			if (num1 > num2) {
				dq.pop_front();
				dq.pop_back();
				dq.push_front({num1 - num2, c1});
			} else if (num1 < num2) {
				dq.pop_front();
				dq.pop_back();
				dq.push_back({num2 - num1, c1});
			} else {
				dq.pop_front();
				dq.pop_back();
			}
		} else {
			ans += min(num1, num2);

			if (num1 > num2) {
				dq.pop_front();
				dq.pop_back();
				dq.push_front({num1 - num2, c1});
			} else if (num1 < num2) {
				dq.pop_front();
				dq.pop_back();
				dq.push_back({num2 - num1, c2});
			} else {
				dq.pop_front();
				dq.pop_back();
			}
		}
	}

	cout << ans;
	return 0;
}
