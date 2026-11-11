#include <bits/stdc++.h>
using namespace std;
int n;
char a[100050];
int zan;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		char s;
		cin >> s;
		for (int j = 1; j <= x; j++) {
			a[zan + j] = s;
			if (j == x)
				zan = j;
		}
	}
	cout << 0;
	return 0;
}