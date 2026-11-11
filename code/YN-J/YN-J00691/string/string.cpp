#include <bits/stdc++.h>
using namespace std;
char brr[200005];
long long arr[200005], s[200005];
int n;
long long ans;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i] >> brr[i];
		s[i] = s[i - 1] + arr[i];
	}
	for (int i = 1, l = 1, j = n; i <= n / 2 + 1; i++) {
		if (arr[l] >= arr[j]) {
			if (brr[l] != brr[j]) {
				ans += arr[j];
			}
			arr[l] -= arr[j];
			arr[j] = 0;
			if (arr[l] <= 0) {
				l++;
			}
			j--;

		} else {
			if (brr[l] != brr[j]) {
				ans += arr[l];
			}
			arr[j] -= arr[l];
			arr[l] = 0;
			l++;
		}
	}
	cout << ans;
	return 0;
}


