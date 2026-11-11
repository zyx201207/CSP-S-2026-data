#include <bits/stdc++.h>
using namespace std;

long long n;
long long a[200005];
char c;
long long L;
long long step;
string S;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c;
		for (int j = L + 1; j <= L + a[i]; j++) {
			S[j] = c;
		}
		L += a[i];
	}
	step = L / 2;
	for (int i = 1; i <= L / 2; i++) {
		if (S[i] == S[L - i + 1]) {
			step--;
		}
	}
	cout << step;
	return 0;
}