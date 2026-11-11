#include <bits/stdc++.h>
using namespace std;
#define fir(i, l, r) for(int i = (l); i <= (int) r; i++)
#define fpr(i, r, l) for(int i = (r); i >= (int) l; i--)
const int maxn = 5e5 + 10;
#define int long long
int a[maxn], n, m, d[maxn], x, pre[maxn];
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

*/
signed main(){
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	fir(i, 1, n) cin >> a[i];
	sort(a + 1, a + n + 1);
	fir(i, 1, n) pre[i] = pre[i - 1] + a[i];
	fir(i, 1, n){
		int L = 1, R = i, ans = i;
		while(L <= R){
			int mid = (L + R) >> 1;
			if((i - mid + 1) * a[i] - pre[i] + pre[mid - 1] > m) L = mid + 1;
			else R = mid - 1, ans = mid;
		}
//		cout << i << endl;
//		cout << ans << endl;
//		cout << (i - ans + 1) * a[i] - pre[i] + pre[ans - 1] << endl;
		x = max(x, i - ans + 1);
	}
	cout << x << endl;
	return 0;
	
}