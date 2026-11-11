#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5 + 10;
int n, a[N];
ll len;
char c[N];

int main () {
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		len += a[i];
	}
//	string S = " ";
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= a[i]; j++)
//			S += c[i];
//	}
//	ll ans = 0;
//	for (int i = 1; i <= len / 2; i++) {
//		if (S[i] != S[len + 1 - i])
//			ans++;
//	}
//	cout << ans;
	ll ans = 0;
	ll len_i = 0, len_j = 0;
	int i = 1, j = n;
	while (i <= j) {
		char x = c[i], y = c[j];
		if (len_i == 0) {
			len_i = a[i];	
		}
		if (len_j == 0) {
			len_j = a[j];
		}	
		if (len_i > len_j) {
			if (x != y) {
				ans += len_j;
			}
			len_i -= len_j;
			len_j = 0;
			j--;
		} else if (len_i < len_j) {
			if (x != y) {
				ans += len_i;
			}
			len_j -= len_i;
			len_i = 0;
			i++;
		} else {
			if (x != y) {
				ans += len_i;
			}
			len_i = len_j = 0;
			i++, j--;
		}
	}
	cout << ans;
	return 0;
}
