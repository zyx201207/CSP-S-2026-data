#include <bits/stdc++.h>
using namespace std;
string a;

string b = {' '};

int c[1000] = {0};

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio;
	cin.tie(0), cout.tie(0);
	int n, m, cnt;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	a.erase(5);
	cout << a;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i] == b[j]) {
				b.erase(j);
				cnt = j;
				break;
			} else if (b[j] == ' ') {
				cnt = j;
				break;
			}
		}
		b[cnt] = a[i];
		for (int j = 0; j < cnt; j++) {
			c[b[j]]++;
		}

	}
	for (int i = 0; i <= m; i++) {
		cout << c[i];
	}
	return 0;
}