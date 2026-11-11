#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18 + 10;
const int N = 2e6 + 10;
int c, t;
int a[N];
void slove(){
	int n, k, ans = 0;
	cin >> n >> k;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	for(int i = 1;i <= n;i++){
		int p[16] = {0};
		int nw = i, cnt = 1;
		p[1] = i;
		while(nw < n){
//			cout << (nw < n) << endl;
			if(nw + k >= a[n]){
				p[++cnt] = n;
				break;
			}
			p[++cnt] = (upper_bound(a + nw + 1, a + n + 1, a[nw] + k) - a - 1);
			nw = p[cnt];
		}
		for(int j = 2;j <= cnt;j++){
			if(p[j] == 0)
				break;
			if(p[j] - p[j - 1] < 2)
				continue;
			else if(p[j] - p[j - 1] == 2)
				ans += max((upper_bound(a + i + 1, a + n + 1, a[p[j] - 1] + k) - a - 1) - p[j], 0ll);
			else
				ans += max(0, (upper_bound(a + i + 1, a + n + 1, a[p[j] - 1] + k) - a - 1) - (upper_bound(a + i + 1, a + n + 1, a[p[j] - 2] + k) - a - 1));
		}
	}
	cout << ans << endl;
}
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.our", "w", stdout);
	cin >> c >> t;
	while(t--){
		slove();
	}
	return 0;
}/*0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6*/