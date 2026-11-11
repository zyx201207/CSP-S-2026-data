#include <bits/stdc++.h>
using namespace std;
#define int long long
#define L(i,j,k) for(int i = (j);i <= (k);i++)
#define R(i,j,k) for(int i = (j);i >= (k);i--)
typedef long long ll;
const int T = 5e5+10;
int n,m,a[T],q[T];
void solve() {
	cin >> n >> m;
	L(i,1,n) cin >> a[i];
	sort(a+1,a+n+1);
	L(i,1,n)q[i]=q[i-1]+a[i];
	int maxv = 1;
	L(i,1,n) {
		int l=i;
		R(j,19,0)
			if(l-(1<<j) >= 1 && q[i]-q[l-(1<<j)-1] + m >= a[i]*(i-(l-(1<<j))+1))
				l -= (1<<j); 
		maxv = max(maxv,i-l+1);
	}
	cout<< maxv;
}
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
//	int t;cin >> t;while(t--)
	solve();
	return 0;
}

