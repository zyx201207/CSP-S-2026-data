#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5;
char c[N];
string s;
long long a[N], ans;
int n;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;

	for (int i = 1; i <= n; i++) {

		cin >> a[i] >> c[i];

		for (int j = 1; j <= a[i]; j++) {

			s += c[i];
		}
	}

	int left = 0, right = s.size() - 1;

	while (left <= right) {
		cout << s[left] << " " << s[right] << endl;

		if (s[left] != s[right]) {
			ans++;
		}

		left++;
		right--;

		if (left == right) {
			break;
		}
	}

	cout << ans;
	return 0;
}
