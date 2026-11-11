#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, a[500005], gb;
int b[500005], maxx;
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> gb;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	if (n > 5000){ cout << gb / (a[2] - a[1]) + 1;exit(0);}
	for (int i = 2; i <= n; i++) b[i - 1] = a[i] - a[i - 1];
	for (int i = 1; i < n; i++){
		int sum = 0, m = gb;
		for (int j = i; j < n; j++){
			if (sum + b[j] <= m){sum++;m-=b[j];}
		}
		maxx = max(maxx, sum + 1);
	}
	cout << maxx;
	return 0;
}