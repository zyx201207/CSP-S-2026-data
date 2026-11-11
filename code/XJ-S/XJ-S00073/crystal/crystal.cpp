#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n , sum = 0;
	long long m , maxn = -1e18, a[500005] , b[500005] = {}, c[500005];
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++){
		b[i] = a[n] - a[i];
		c[i] = b[i] - b[i + 1];
	}
	for (int i = 1; i <= a[0]; i++){
		long long num = 0 , ans = 0;
		for (int j = 1; j <= n; j++){
			num += a[i + j - 1] * j;
			if (num >= m) break;
			ans++;
		}
		maxn = max(maxn , ans);
	}
	cout << maxn;
	return 0;
}

