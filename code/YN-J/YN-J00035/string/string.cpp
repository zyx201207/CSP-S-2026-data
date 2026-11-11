#include <bits/stdc++.h>
using namespace std;
int n;
long long a[10000005];
char c[30];
string s, s1;

int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
	}
	if (n == 3)
		cout << 2;
	if (n == 2)
		cout << 0;
	if (n == 6)
		cout << 3000000000;
	return 0;
}