#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;
int a[N];
int n, Left, Right;
int k;

signed main(void) {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> Left;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	if (Left / n == Right / n) {
		cout << Right % n;
	} else {
		cout << n - 1;
	}
	return 0;
}
/*
max(n mod k) =  n - 1
if(Left/n == Right/n)
max(n mod k) = Right mod n
*/