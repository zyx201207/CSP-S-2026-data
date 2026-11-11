#include<bits/stdc++.h>
#define int long long

#define rep(K,F,T) for(int K=F;K<=T;K++)
#define rip(K,F,T) for(int K=F;K>=T;K--)

//#define lson (x<<1)
//#define rson ((x << 1) | 1)
//#define mid ((l + r) >> 1)

using namespace std;

namespace florr{
	int read() {
		int x = 0, f = 1;
		char ch = getchar();
		while(ch < '0' || ch > '9') {
			if(ch == '-') f = -1;
			ch = getchar();
		}
		while(ch >= '0' && ch <= '9') {
			x = x * 10 + (ch - '0');
			ch = getchar();
		}
		return x * f;
	}
	void write(int x) {
		if(x < 0) {
			putchar('-');
			x = -x;
		}
		if(x > 9) write(x / 10);
		putchar(x % 10 + '0');
		return;
	}
}
using namespace florr;
const int MAXN = 2e6 + 10;
int C, T, a[MAXN];
int n, d, mx[MAXN], lmx[MAXN], smx[MAXN], lsmx[MAXN]; 
bool isss[MAXN];
int  tot = 0, g[MAXN], dp[MAXN], ldp[MAXN];
void solve()
{
	int ans = 0;
	n = read(), d = read();
	rep(i,1,n) a[i] = read();
//	rep(i,1,n)
	int pos = n;
	rip(i,n,1) {
		isss[i] = false;
		while(a[pos] - a[i] > d) pos --;
		mx[i] = pos;
		smx[i] = i;
		smx[i] = smx[mx[i]];
	}
//	return ;
	rep(i,1,n) {
		rep(j,i + 3,n){
//			cout << i << " " << j << "\n";
			int q = i;
			int tot = 0;
			while(q < j) {
				int t0 = min(j, mx[q]);
				int f = q-1;
				while(f >= i and mx[f] >= t0 ) {
					tot ++;
					f --;
//					cout <<f;
				}
				if(q == t0) {
					tot = 0;
					break;
				} 
				q = t0; 
			}
			if(tot == 1) ans ++;
		}
	}
//	pos = 1;
//	rep(i,1,n) {
//		while(a[i] - a[pos] > d) pos ++;
//		lmx[i] = pos;
//		lsmx[i] = i;
//		lsmx[i] = lsmx[lmx[i]];
//	}
//	rep(i,2,n-2) {
//		if(mx[i-1] == i + 1 and mx[i] >i + 1) {
//			g[++tot] = i; 
//		} 
//	}
//	int ans = 0;
//	dp[1] = 1, dp[2] = 2 - lsmx[2] + 1;
//	rep(i,3,n) {
//		if(a[i] - a[i-1] > d) {
//			dp[i] = 1;
//			continue;
//		}
//		if(a[i] - a[i - 2] > d){
//			dp[i] = dp[i-1] + 1;
//		}
//		else dp[i] = 2;
//	}
//	ldp[n] = 1, ldp[n - 1] = smx[n - 1] - n + 2;
//	rip(i, n-2, 1) {
//		if(a[i + 1] - a[i] > d) {
//			ldp[i] = 1;
//			continue;
//		}
//		if(a[i +2] - a[i] > d) ldp[i] = ldp[i+1] +1;
//		else ldp[i] = 2;
//	} 
//	rep(i,1,n) {
//		cout << mx[i] <<" ";
//		rep(j,i +1,smx[i]) {
////			cout << i << " " << j;
//			int tot2 = 0;
//			rep(k,1,tot) {
////				cout << g[k];
//				if(g[k] > i and g[k]+1 < j) {
//					tot2 ++;
//				}
//			}
//			if(tot2 == 1) ans ++;
//		}
//	}
//	rep(i,1,tot ) {
////		cout << g[i] << " ";
//		ans += (dp[g[i]] - 1) * (ldp[g[i] + 1] - 1 );
//	}
	write(ans);
	putchar('\n');
	return;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out", "w",stdout);
	C = read(), T =read();
	while(T--) {
		solve();
	}
	return 0;
}
/*
1 1
6 1200000000000000000
 
-1000000000000000000 -600000000000000000 -200000000000000000 200000000000000000 600000000000000000 1000000000000000000

*/

