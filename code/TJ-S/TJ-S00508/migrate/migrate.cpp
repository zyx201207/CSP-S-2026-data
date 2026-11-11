#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e6 + 10;
int c, t, n;
long long d, ans, a[maxn], f[maxn], cnt[maxn];
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t--) {
		cin >> n >> d;
		for(int i = 1; i <= n; i++) cin >> a[i];
		ans = 0;
		for(int st = 1; st <= n; st++) {
			f[st] = 0;
			cnt[st] = 1;
			int pre = st;
			for(int ed = st + 1; ed <= n; ed++) {
				while(a[ed] - a[pre] > d) pre++;
				if(pre == ed) break;
				f[ed] = f[pre] + 1;
				int pre2 = pre;
				for(int i = 1; i <= 2; i++) {
					if(f[pre+i] == f[pre]) pre2 = pre + i;
					else break;
				}
				if(pre2 == pre + 2) cnt[ed] = 3;
				else if(pre2 == pre + 1) {
					if(cnt[pre] + cnt[pre + 1] > 2) cnt[ed] = 3;
					else cnt[ed] = 2;
				}
				else {
					cnt[ed] = cnt[pre];
				}
				if(cnt[ed] == 2) ans++;
				//cerr << "(" << f[ed] << "," << cnt[ed] << ")  ";
			}
			//cerr << endl;
		}
		cout << ans << endl;
	}
	return 0;
}
