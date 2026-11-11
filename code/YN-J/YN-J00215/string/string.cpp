#include <iostream>
using namespace std;
long long a[30];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	if (n == 1) {
		cout << 0;
		return 0;
	} else {
		long long sum_l = 0;
		int cnt1 = 0, cnt = 0;
		for (int i = 1; i <= n; i++) {
			char s1;
			long long l;
			cin >> l;
			sum_l += l;
			char s;
			cin >> s;
			if (s != s1) {
				cnt1++;
			}
			a[(int)s - 96] += l;
			s1 = s;
		}
		if (cnt1 == 1) {
			cout << 0;
			return 0;
		}
		if (cnt1 == 2) {
			cout << sum_l / 2;
			return 0;
		} else {
			string s;
			for (int i = 1; i <= 26; i++) {
				for (int j = 1; j <= a[i]; j++) {
					if (a[i] != 0) {
						s += (char)(i + 96);
					}
				}
			}
			if (sum_l % 2 == 0) {
				int l = sum_l / 2;
				int r = sum_l / 2 + 1;
				while (l >= 1 && r <= (s.size() - 1)) {
					if (s[l] != s[r]) {
						cnt++;
					}
					l--;
					r++;
				}
			} else {
				int l = sum_l / 2;
				int r = sum_l / 2;
				while (l >= 0 && r <= (s.size() - 1)) {
					if (s[l] != s[r]) {
						cnt++;
					}
					l--;
					r++;
				}
			}
		}
		cout << cnt;
	}
	return 0;
}