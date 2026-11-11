#include <bits/stdc++.h>
using namespace std;
int t[100000005];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long t1, ans = 0;
	cin >> t1;
	string sum = "";
	int i = 0, j = t1 - 1, k = 0;

	while (t1--) {
		int n;
		char s;
		cin >> n >> s;
		sum += s;
		t[k] = n;
		k++;
	}


	while (i < j) {
		if (sum[i] != sum[j]) {
			ans += min(t[i], t[j]);
			int z = t[i], x = t[j];
			t[i] -= min(z, x);
			t[j] -= min(z, x);

			if (t[i] == 0)
				i++;

			if (t[j] == 0)
				j--;
		} else if (sum[i] == sum[j]) {
			int z = t[i], x = t[j];
			t[i] -= min(z, x);
			t[j] -= min(z, x);

			if (t[i] == 0)
				i++;

			if (t[j] == 0)
				j--;
		}
	}

	cout << ans;
}
