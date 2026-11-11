#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long a[100005];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout<<m<<m-2<<m+1;
	return 0;
}