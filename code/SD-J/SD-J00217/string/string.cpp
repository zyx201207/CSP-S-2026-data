#include <bits/stdc++.h>
using namespace std;
long long n, a[200005], ans;
char c[200005];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; ++i){
		cin >> a[i] >> c[i];
	}
	int l = 1, r = n;
	while (l != r){
		long long C = max(a[l], a[r]), D = min(a[l], a[r]);
		if (c[l] != c[r]) ans += D;
		if (a[l] == C){
			--r;
			a[l] -= D;
		}else{
			++l;
			a[r] -= D;
		}
	}
	cout << ans;
	return 0;
}
