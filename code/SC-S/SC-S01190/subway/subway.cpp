#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int w[N], k[N];
//int z[N][510], ctt[N];
int c, n, m, d, q, ans = 1e18;
struct node {
	int k;
	int a[20], t[20];
}sub[N];
//void dfs(int step, int y, int sum) {
//	if(step == y) {
//		ans = min(ans, sum);
//	}
//	for(int i = 1; i <= ctt[step]; i++) {
//		for (int j = 1; j <= sub[i].k; j++) {
//			dfs(j, y, sum + w[sub[i].k]);
//		}
//	}
//}
signed main() {
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> sub[i].k;
		for (int j = 1; j <= sub[i].k; j++) cin >> sub[i].a[j] >> sub[i].t[j];
//		z[sub[i].k][++ctt[sub[i].k]] = i;
	}
	while(q--) {
		int x, y;
		cin >> x >> y;
//		if(c >= 7 && c <= 11) {
//			dfs(x, y, 0);
//			cout << ans;
//	    }
		if(c == 20 || c == 21) {
			int flag = 0, flag1 = 0, flag2 = 0, x1d, x2d, st[3], flag3 = 0;
			for (int i = 1; i <= sub[1].k; i++) 
				for (int j = 1; j <= sub[2].k; j++) 
					if(sub[1].a[i] == sub[2].a[j] && sub[1].a[i] == x) 
						flag = 1;
			for (int i = 1; i <= sub[1].k; i++) {
				if(sub[1].a[i] == y) flag1 = 1, x1d = i;
				if(sub[1].a[i] == x) st[1] = i, flag3 = 1;
			}
			for (int i = 1; i <= sub[2].k; i++) {
				if(sub[2].a[i] == y) flag1 = 1, x2d = i;
				if(sub[2].a[i] == x) st[2] = i, flag3 = 2;
			}
			if(flag == 1) {
				if(flag1 == 1) ans = min(ans, sub[1].a[x1d] + sub[1].a[st1]);
				if(flag2 == 1) ans = min(ans, sub[2].a[x2d] + sub[2].a[st2]);
			} else {
				ans = min(ans, sub[flag3].a[st[flag3]] + 1);
			}
		}
		
	}
	return 0;
}