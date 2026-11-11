#include <bits/stdc++.h>
using namespace std;
#define int long long
#define L(i,j,k) for(int i = (j);i <= (k);i++)
#define R(i,j,k) for(int i = (j);i >= (k);i--)
typedef long long ll;
int n,d;
const int T = 2e6+10,inf = 1e18;
int x[T],l[T],r[T];
const int T2 = 5e3+10;
int dp[T2][T2],c[T2][T2];
int op;
int cnt[T];
int s[T],hl,hr;
void solve() {
	cin >> n >> d;
	L(i,1,n) cin >> x[i];
//	cout << "??\n";
//	cout << n << d << '\n';
	int xia = 1;
	L(i,1,n) {
		while(xia < n && x[xia+1]-x[i] <= d) xia++;
		r[i] = xia;
	}
	xia = n;
	R(i,n,1) {
		while(xia > 1 && x[i]-x[xia-1] <= d) xia--;
		l[i] = xia;
	}
//	L(i,1,n) {
//		cout << l[i] << ' ' << r[i] << '\n';
//	}
	if(0 <= op && op <= 10) {
		 int ans = 0 ;
		dp[1][1] = 0,c[1][1] = 1;
		L(i,1,n) {
			dp[i][i] = 0,c[i][i] = 1;
			hl = hr = 1;
			s[hl] = i;
			cnt[0]++;
			L(j,i+1,n) {
				if(l[j] == j) {
	//				while(hl <= hr) cnt[dp[i][s[hl]]]--,hl++;
	//				cout << "del" << i << ' ' << j << '\n';
					break;
				}
				while(hl <= hr && s[hl] < l[j]) cnt[dp[i][s[hl]]] -= c[i][s[hl]],hl++;
				int v = dp[i][s[hl]];
				if(cnt[v] == 2) ans++;
				dp[i][j] = v+1;
				c[i][j] = cnt[v];
				while(hl <= hr && dp[i][s[hr]] > dp[i][j]) cnt[dp[i][s[hr]]] -= c[i][s[hr]],hr--;
				s[++hr] = j;
				cnt[dp[i][s[hr]]] += c[i][j];
			}
			while(hl <= hr) cnt[dp[i][s[hl]]] -= c[i][s[hl]],hl++;
		}
		cout << ans << '\n';
		return ;
	}
	if(13 <= op && op <= 14) {
		L(i,1,n) cnt[l[i]]++;
		int sum = 0;
		L(i,1,n) {
			sum += cnt[r[i]-1];
		}
		cout << sum << '\n';
		return ;
	}
}
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
//	freopen("my.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> op >> t;while(t--)
	solve();
	return 0;
}
/*
10 272727272727272724
-999999999999999976 -727272727272727252 -454545454545454528 -181818181818181804 -90909090909090896 12 181818181818181828 454545454545454552 727272727272727276 1000000000000000000
*/
