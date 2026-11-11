#include <bits/stdc++.h>

#define PII pair <int,int>
#define fi first
#define se second
#define all(u) (u).begin(),(u).end()
#define lb lower_bound
#define ub upper_bound
#define INF (1ll << 30) - 1
#define int long long
#define ll long long
#define N 1000005

using namespace std;
int n,m;
int a[N],A[N],B[N];
void I() {
	int res = 0;
	for(int s = 0;s < (1 << n);s ++) {
		int ans = (1 << n) - 1;
		if(__builtin_popcount(s) != m) continue;
		for(int i = 1;i <= n;i ++) {
			if(!(s >> (i - 1) & 1)) continue;
			ans &= a[i];
		}
		res = max(res,ans);
	}
	cout<<res<<"\n";
}
bool is_A() {
	for(int i = 1;i <= n;i ++) {
		if(((a[i] + 1) & a[i])) return 0;
	}
	return 1;
}
signed main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
//	freopen("and3.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i ++) cin>>a[i];
	if(n <= 20) I();
	else if(n <= 2000) {
		if(m == 1) {
			int res = 0;
			for(int i = 1;i <= n;i ++) res = max(res,a[i]);
			cout<<res<<"\n";
		}
		else if(m == 2) {
			int res = 0;
			for(int i = 1;i <= n;i ++) {
				for(int j = 1;j <= n;j ++) {
					if(i != j) res = max(res,a[i] & a[j]);
				}
			}
			cout<<res<<"\n";
		}
		else if(m == n) {
			int res = INF;
			for(int i = 1;i <= n;i ++) {
				res &= a[i];
			}
			cout<<res<<"\n";
		}
	}
	else {
		if(m == n - 1) {
			int res = 0;
			A[0] = INF,B[n + 1] = INF;
			for(int i = 1;i <= n;i ++) {
				A[i] = A[i - 1] & a[i];
			}
			for(int i = n;i >= 1;i --) {
				B[i] = B[i + 1] & a[i];
			}
			for(int i = 1;i <= n;i ++) {
				res = max(res,A[i - 1] & B[i + 1]);
			}
			cout<<res<<"\n";
		}
		else if(is_A()) {
			sort(a + 1,a + n + 1,greater <int> ());
			int res = INF;
			for(int i = 1;i <= m;i ++) {
				res &= a[i];
			}
			cout<<res<<"\n";
		}
		else {
			cout<<"0\n";
		}
	}
	return 0;
}

