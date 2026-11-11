#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define rep(i, b, e) for(int i=b; i<=e; i++)
#define per(i, e, b) for(int i=e; i>=b; i--)
#define pb push_back

ll qpow(const ll&a, ll b, const ll& MOD) {
	ll res=1, base=a;
	for(; b; b>>=1, base=base*base%MOD) if(b&1) res=res*base%MOD;
	return res;
}

const int N=2e6+5;
const ll INF=1e18;

int n;
ll d;
ll x[N];

int f[N], w[N];
int calc(int l, int r) {
	int res=0;
	rep(i, l, r) {
		f[i]=1e9;
		w[i]=0;
	}
	f[l]=0; w[l]=1;
	rep(i, l+1, r) { //O(n)
		int idx=int(lower_bound(x+l, x+i, x[i]-d)-x);//O(log n)
		if(w[idx]>2) break;
		for(f[i]=f[idx]+1; idx<i; idx++) {
			if(f[idx]>=f[i] || w[i]>2) break;//O(1)
			w[i]+=w[idx];
		}
		res+=(w[i]==2);
	}
	return res;
	// O(n log n)
}

//将x[i]-x[i-3]>d, x[i]-x[i-2]<=d的点称为关键点
//则经过关键点时方案数会上升为2(all 1 sequence)
//然后找出以关键点为起点的最大支配+链的束
//向前再延申一个支配链
//贡献前*后 
//寻找应该是可以均摊的 

void solve() {
	cin >> n >> d;
	rep(i, 1, n) cin >> x[i];
	x[n+1]=x[n]+d+5;
	int ans=0;
	int l=1;
	rep(i, 1, n) {
		if(x[i+1]-x[i]>d) {
			rep(j, l, i) ans+=calc(j, i);
			l=i+1;
		}
	}//O(n^2 log n)
	cout << ans << '\n';
}


int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
	
	int c, t; cin >> c >> t;
	while(t--) solve();

	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/

/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/