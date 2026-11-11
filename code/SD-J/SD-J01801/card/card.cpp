#include<bits/stdc++.h>
using namespace std;
int a[500005];
bool f = 0;
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		if(a[i] != a[i - 1]) {
			f = 1;
		} 
	}
	if(f = 1) {
		for(int i = 1; i <= m; i++) {
			cout << n << " ";
		}
	}
	else {
		for(int i = 1; i <= m; i++) {
			cout << 0 << " ";
		}
	}
	return 0;
}
