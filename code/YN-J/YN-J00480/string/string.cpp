#include <bits/stdc++.h>
using namespace std;
int a[10101];
char s[1010];
string zi;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, sum = 0;
	int kong = 0;
	cin >> n;
	bool f = 0;
	for (int i = 1; i <= n; i++) {
		char s1 = s[0];
		cin >> a[i] >> s[i];
		kong += a[i];
		for (int j = 1; j <= a[i]; j++) {
			zi[j] = s[i];
		}
	}
	int cp = 0;
	for (int i = 1; i <= zi.length(); i++) {
		if (zi[i] != zi[i + 1]) {
			cp++;
		}
	}
	if (cp == 0) {
		cout << 0;
		return 0;
	}
	for (int i = 1; i <= kong; i++) {
		for (int j = kong; j >= 1; j--) {
			if (zi[i] != zi[j]) {
				if (zi[i + 1] != zi[j]) {
					char h = zi[i + 1];
					zi[i + 1] = zi[j];
					zi[j] = h;
					sum++;
					continue;
				} else {
					char h = zi[i + 1];
					int zkd = i / 2;
					zi[i + 1] = zi[zkd];
					zi[zkd] = h;
					sum++;
					continue;
				}
			}
		}
	}
	cout << sum / (n / 2);
	return 0;
}