#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int c,t;
signed main(){
	cin >> c >> t;
	while (t--){
		int n,d,a[N];
		cin >> n >> d;
		for (int i = 1;i <= n;i++) cin >> a[i];
		int c = a[n] - a[n-1];
		if (d >= c && d < 2 * c) cout << n - 2 << endl;
		else cout << 0 << endl;
	}
	return 0;
}
