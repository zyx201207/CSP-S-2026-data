#include <bits/stdc++.h>
using namespace std;
int  n;
int a[1000005];
string c[100005];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		cin >> c[i];
		for (int j = i; j <= a[i]; j++) {
			cout << c[i];
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}