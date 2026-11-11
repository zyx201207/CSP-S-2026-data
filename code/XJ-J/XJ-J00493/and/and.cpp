#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2E5 + 10;
int n, m, ans, cnt;
int a[N];
int f = (1 << 21) - 1;
int calc(int k) {
	int c;
	while(k) {
		if(k&1) {
			cnt++;
		}
		k = (k >> 1);
	}
	return c;
}
int cmp(int o,int p) {
	return o > p;
}
void dfs(int k,int t,int v) {
	cnt ++;
	if(t > m) {
		return ;
	}
	if(k == n + 1) {
		if (t == m) {
			if(v != f) {
				ans = max(ans,v);
			}
		}
		return ;
	}
	dfs(k + 1,t + 1,(v & a[k]));
	dfs(k + 1, t, v);
}
signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if(n <= 20) {
		dfs(1, 0, f);
		cout << ans;
		return 0;
	}//考虑subtask 1-5 except 25 pts
	else if(n <= 2000) {
		if(m == 1) {
			for(int i = 1; i<= n; i++) {
				ans = max(ans,a[i]);
			}
			cout << ans;
			return 0;
		}//sub 6
		if(m == n) {
			for(int i = 1; i<= n; i++) {
				ans = (ans & a[i]);
			}
			cout << ans;
			return 0;
		}//sub 7
		if(m == 2) {
			for(int i = 1; i<= n; i++) {
				for(int j = 1; j<= n; j++) {
					ans = max(ans ,(a[i] & a[j]));
				}
			}
			cout << ans;
			return 0;
		}//sub 8-10
	} else {
		if(m == n - 1) {
			int minn = INT_MAX , sf , ct;
			for(int i = 1 ; i <= n; i++) {
				if(calc(a[i])<minn) {
					minn = calc(a[i]);
					sf = a[i];
				}
			}
			for(int i = 1; i <= n ; i++) {
				if(a[i] != sf &&ct == 0) {
					ct = 1;
					ans = (ans & a[i]);
				}
			}
			cout << ans ;
			return 0;
		}//sub 11-12
		int flag1 = 1,flag2 = 1,flag3 = 1;
		for(int i = 1; i <= n; i++) {
			if(a[i]%2 == 0) {
				flag1 = 0;
			}
			if(!(a[i] == i - 1)) {
				if(i != 1) {
					flag2 = 0;
				}
			}
			if(a[i]>=4) {
				flag3 = 0;
			}
		}
		if(flag1 == 1) {
			sort (a + 1, a + n + 1, cmp);
			for(int i = 1; i <= m; i++) {
				ans = (ans & a[i]);
			}
			cout << ans;
			return 0;
		}//sub13
		if(flag2 == 1) {
			sort (a + 1, a + n + 1, cmp);
			for(int i = 1; i <= m; i++) {
				ans = (ans & a[i]);
			}
			cout << ans;
			return 0;
		}//sub14-15
		if(flag3 == 1) {
			sort (a + 1, a + n + 1, cmp);
			for(int i = 1; i <= m; i++) {
				ans = (ans & a[i]);
			}
			cout << ans;
			return 0;
		}//sub16-17
		else {
			dfs(1, 0, f);
			cout << ans << endl;
			return 0;
		}//sub18-20
	}
	return 0;
}
//这雷霆部分分给的真足
