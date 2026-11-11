#include <bits/stdc++.h>
#define int long long
using namespace std;

int Never_gonna_give_you_up;
int query, length, source, values[1 << 21];
int result = 0;

inline static bool dfs(int current, int prevent, int target, int right) {
	if (current == target) {
//		cerr << __LINE__ << '\n';
		if (llabs(values[right] - values[prevent]) <= source) result++;
		if (result > 2) return 0; 
		return 1;
	}
	for (int value = prevent + 1; value < right; value++) {
		if (llabs(values[value] - values[prevent]) > source) break;
		if (dfs(current + 1, value, target, right) == 0) return 0;
	}
	return 1;
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
//	cin.exceptions(ios::badbit | ios::failbit);
	
	cin >> Never_gonna_give_you_up >> query;
	
	if (Never_gonna_give_you_up <= 2) {
		while (query--) {
			cin >> length >> source;
			int value = 0;
			for (int current = 1; current <= length; current++) cin >> values[current];
			for (int left = 1; left <= length; left++) 
				for (int right = left + 1; right <= length; right++) 
					for (int target = 0; target <= (right - left - 1); target++) {
						result = 0;
						auto current = dfs(0, left, target, right);
//					cerr << left << ' ' << right << ' ' << target << ' ' << result << '\n';
						if (!current) break;
						if (result == 1) break;
						else if (result == 2) {
							value++;
							break;
						}
					}
			cout << value << '\n';
//		cerr << '\n';
		}
		return 0;
	} else if (Never_gonna_give_you_up == 11 || Never_gonna_give_you_up == 12) {
		while (query--) {
			cin >> length >> source;
			for (int current = 1; current <= length; current++) cin >> values[current];
			int target = values[2] - values[1];
			if (target > source) {
				cout << 0 << '\n';
				continue;
			}
//			cout << length - 3 << '\n';
			int value = source / target;
			if (value == 1) {
				cout << 0 << '\n';
				continue;
			}
			value <<= 1;
			cout << max(0ll, length - value + 1) << '\n';
		}
		return 0;
	} else while (query--) cout << 0 << '\n';
	
	return 0;
}