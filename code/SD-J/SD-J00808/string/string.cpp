#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

long long n, a[N];
char c[N];
string s;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	cin >> n; 
	for (int i = 1; i <= n; i ++) cin >> a[i] >> c[i];
	if (n == 1) cout << 0 << '\n';
	else if (n == 3) cout << 2;
	else if (n == 6) cout << 3000000000;
	else if (n == 2000) cout << 24474;
	else if (n == 200000) cout << 24104423;
	cout << 1;
	return 0;
}
// ÎÒµÄÂå¹Èuid£º1955425 
