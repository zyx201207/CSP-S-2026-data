#include <bits/stdc++.h>
using namespace std;

int s[6005] = {};

void clean(int a, int b) {
	for (int i = a; i <= b; i++) {
		s[i] = 0;
	}
}



int main() {

	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);

	int n, m;
	int card[5005] = {};
	cin >> n >> m;
	int ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0, ans5 = 0;
	for (int i = 1; i <= n; i++) {
		cin >> card[i];
	}
	for (int i = 1; i <= n; i++) {
		s[i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			s[j] = card[j];
		}
		for (int j = i; j <= n; j++) {
			for (int k = j; k <= n; k++) {
				if (s[j] == s[k]) {
					clean(j, k);
				}
			}
		}
		for (int j = 1; j <= n; j++) {
			if (s[j] == 1) {
				ans1++;
			} else if (s[j] == 2) {
				ans2++;
			} else if (s[j] == 3) {
				ans3++;
			} else if (s[j] == 4) {
				ans4++;
			} else if (s[j] == 5) {
				ans5++;
			}
		}

	}
	if (m >= 1) {
		cout << ans1 << " ";
	}
	if (m >= 2) {
		cout << ans2 << " ";
	}
	if (m >= 3) {
		cout << ans3 << " ";
	}
	return 0;
}