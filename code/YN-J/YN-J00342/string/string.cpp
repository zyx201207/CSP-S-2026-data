#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int N = 2e5 + 5;

ll n, a, cnt;
char c;

struct Node {
	ll a;
	char c;
} k[N];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;

	for (int i = 1; i <= n; i++) {

		cin >> k[i].a >> k[i].c;

	}

	ll sum = n, i = 1;

	while (sum != i) {
		if (k[i].a < k[sum].a) {
			k[sum].a -= k[i].a;

			if (k[sum].c != k[i].c) {
				cnt += k[i].a;
			}

			i++;
		} else {
			k[i].a -= k[sum].a;

			if (k[sum].c != k[i].c) {
				cnt += k[sum].a;
			}

			sum--;
		}
	}

	cout << cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}