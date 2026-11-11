#include "bits/stdc++.h"
#define For(i, l, r) for(ll i=(l); i<=(r); ++i)
#define Rof(i, r, l) for(ll i=(r); i>=(l); --i)
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll n, m, a[N], pre[N], cnt, ans=1;

ll pos1, pos2, res;

bool check(ll l, ll r) {
	ll sum=pre[r-1]-pre[l-1];
	if(m+sum>=a[r]*(r-l)) return 1;
	else return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin>>n>>m;
	For(i, 1, n) cin>>a[i];
	sort(a+1, a+n+1);
	For(i, 1, n) pre[i]=pre[i-1]+a[i];
	
	For(i, 1, n) {
		ll l=0, r=i-1, mid;
		while(l<r-1) {
			mid=(l+r)>>1;
			if(check(mid, i)) {
				r=mid;
			}
			else {
				l=mid;
			}
		}
		r=max(1ll, r);
		if(i-r+1>ans) ans=max(ans, i-r+1);
	}
	cout<<ans<<endl;
	
	return 0;
}
/*
I LOVE CCF
give me 100pts plz
STO CCF OTZ

1001001
000001
0011001
1111001
0110101
1010001
000001
0101101
1100001
0001101

zzzzzzz
*/
