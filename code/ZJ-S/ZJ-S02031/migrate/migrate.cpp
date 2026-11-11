#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 10;
int c, t, n, d;
int a[N];
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> c >> t;
	while(t --){
		int ans = 0;
		cin >> n >> d;
		for(int i = 1; i <= n; i ++) cin >> a[i];
		for(int i = 4; i <= n; i ++)
			if(2 * d == i * (a[i] - a[i - 1])){
				ans = n - i + 1;
				break;
			}
		cout << ans << endl;
	}
	
	return 0;
}
