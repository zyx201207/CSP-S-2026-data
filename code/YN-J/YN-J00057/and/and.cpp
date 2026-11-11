#include <bits/stdc++.h>
using namespace std;
long long q = 0, n, s;

int main() 
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> s;
	long long a[100005];
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n - i; j++) {
			if(i+j<=n){
				if ((a[i] and a[i + j]) > q) {
					q = (a[i]) and (a[i + j]);
				}
			}
		}
	}

	cout << q;
	return 0;
}
