#include <bits/stdc++.h>
using namespace std;
int n;
long long m;
const long long N = 5e5 + 5;
long long a[N];
long long cnt = 0;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	cout << n;
	return 0;
} 
