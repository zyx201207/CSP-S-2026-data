#include <bits/stdc++.h>
using namespace std;
string a;
int cnt;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m, wow[n + 5];
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> wow[i];//^v^
		a += wow[i];
	}
	for (int i = 1; i <= m; i++) {
		if (a.find(i) != 0) {
			cnt++;
		}
	}
	cout << cnt;//<3
}