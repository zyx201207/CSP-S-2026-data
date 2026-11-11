#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 10;
int c, T, n, d;
int a[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> T;
	while(T--){
		int ans = 0;
		cin >> n >> d;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		int q = a[n] - a[n - 1];
		
		if(q > d)
			cout << 0 << endl;
		int x = (d + 1) / q, y = (2 * d - 1) / q;
		for(int i = x + 1; i <= min(n, y); i++)
			ans += (n - i + 1);
		cout << ans << endl;
	}
	return 0;
}