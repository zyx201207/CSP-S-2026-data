#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;

struct node {
	int s;
	char c;
} a[N];
int n;
set<char>s1;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].s >> a[i].c;
		s1.insert(a[i].c);
	}
	if (s1.size() == 1) {
		cout << 0;
		return 0;
	}
	long long ans = 0;
	int i = 1;
	int j = n;
	while (i <= j) {
		if (a[i].c != a[j].c) {
			if (a[i].s <= a[j].s) {
				a[i].c = a[j].c;
				ans += a[i].s;
			} else {
				a[j].c = a[i].c;
				ans += a[j].s;
			}
		}
		if (a[i].s != a[j].s) {
			ans++;
			if (a[i].s < a[j].s) {
				a[i + 1].s--;
				a[i + 1].c = a[i].c;
			} else {
				a[j - 1].s--;
				a[j - 1].c = a[j].c;
			}
		}
		i++;
		j--;
	}
	cout << ans;
	return 0;
}