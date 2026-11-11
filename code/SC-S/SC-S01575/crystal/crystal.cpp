#include <bits/stdc++.h>
#define int long long
using namespace std;

int length, target;
int values[1 << 20];
int result = -1e18;

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
//	cin.exceptions(ios::badbit | ios::failbit);
	
	cin >> length >> target;
	
	for (int current = 1; current <= length; current++) cin >> values[current];
	sort(values + 1, values + length + 1);
	
	if (length <= 5000) {
		for (int left = 1; left <= length; left++) {
			int source = 0;
			for (int right = 1; left + right <= length; right++) {
				int current = left + right;
				int value = values[current] - values[current - 1];
				source += value * right;
				if (source > target) {
					result = max(result, right);
//				cerr << right << '\n';
					break;
				} else if (left + right == length) {
					if (result < right) return cout << right << '\n', 0;
					else return cout << result << '\n', 0;
				}
			}
		}
		// Process exited after 395.3 seconds with return value 0 (3.81e+05 ms cpu time, 9268 KB mem used).
		cout << result << '\n';
		return 0;
	}
	
	int source = 0;
	for (int current = 2; current <= length; current++) {
		int value = values[current] - values[current - 1];
		source += value * (current - 1);
		if (source > target) return cout << current - 1 << '\n', 0;
	}
	cout << length << '\n';
	
	return 0;
}