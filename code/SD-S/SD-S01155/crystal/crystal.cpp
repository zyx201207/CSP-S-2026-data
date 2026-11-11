// chennie bless me 
#include<bits/stdc++.h>
#define int long long
#define __FILE_IO__(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
#define all(x) x.begin(), x.end()
#define All(x) x.begin() + 1, x.end()
#define rep(i,l,r) for(int i = (l);i <= (r); ++i)
#define per(i,l,r) for(int i = (l);i >= (r); --i)
using vi = std::vector<int>;
using pii = std::pair<int,int>;
#define in std::cin
#define out std::cout
void ckmax(int &a,int b) { a = std::max(a,b); }
void ckmin(int &a,int b) { a = std::min(a,b); }

int abs(int x) {
	if(x < 0) return -x;
	return x;
}

void solve(){
	int n, m; in >> n >> m;
	vi a(n+1);
	rep(i,1,n) in >> a[i];
	sort(All(a),[&](int x,int y) {
		return x > y;
	});
	std::deque<int> q;
	int l = 1, tmp = 0, ans = 0;
	rep(r,1,n) {
		tmp += abs(a[r] - a[l]);
		while(tmp > m && l < r) {
			l++;
			tmp += (a[l] - a[l-1]) * (r - l + 1); 
		}
		ckmax(ans,r-l+1);
	}
	out << ans << '\n';
}

signed main() {
	__FILE_IO__("crystal");
	std::ios::sync_with_stdio(0), in.tie(0);  
	int T = 1;
//	in >> T;
	while(T--) {
		solve();
	}
	return 0;
}
