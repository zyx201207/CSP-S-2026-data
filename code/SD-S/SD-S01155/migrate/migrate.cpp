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
#define fi first
#define se second

const int N = 5e5+10;
int c; 

int abs(int x) {
	if(x < 0) return -x;
	return x;
}

struct DSU{
	int fa[N];
	void init(int n) {
		rep(i,1,n) fa[i] = i;
	}
	int fd(int x) {
		if(fa[x] == x) return x;
		return fa[x] = fd(fa[x]);
	}
	void mg(int x, int y) {
		x = fd(x), y = fd(y);
		x = fa[y];
	}
} d;

void bt() {
	int n, D; in >> n >> D;
	vi x(n+1);
	rep(i,1,n) in >> x[i];
	if(c == 11 || c == 12) {
		if(x[3] - x[1] <= D) {
			n /= 2;
			return out << n * (n - 1) / 2, void();
		}
		return out << "0\n", void();
	}
	int ans = 0;
	rep(i,1,n) rep(j,i+3,n) {
		int cnt = 0, fl = 0;
		rep(k,i,j) if(x[k] - x[k-1] > D) {
			fl = 1;
			break;
		}
		if(fl) break;
		rep(k,i,j-3) {
			if(x[k+3]-x[k] <= D) continue;
			if(x[k+1]-x[k] <= D && x[k+3]-x[k+1] <= D && x[k+2]-x[k] <= D && x[k+3]-x[k+2] <= D) cnt++;
		}
		if(cnt == 1) {
			ans++;
		}
	}
	out << ans << '\n';
}

signed main() {
	__FILE_IO__("migrate");
	std::ios::sync_with_stdio(0), in.tie(0);  
	int T = 1;
	in >> c;
	in >> T;
	while(T--) {
		bt();
	}
	return 0;
}

//void solve(){
//	int n, D; in >> n >> D;
//	vi x(n+1);
//	rep(i,1,n) in >> x[i];
//	d.init(n);
//	rep(i,1,n) {
//		int l = 0, r = n - i, res = 0;
//		while(l <= r) {
//			int mid = (l + r) / 2;
//			if(x[i+mid] - x[i] <= D) {
//				l = mid + 1;
//				res = mid;
//			} else r = mid;
//		}
//		d.mg(i,i+res);
//	}
//	int ans = 0;
//	std::map<int,int> mp;
//	rep(i,1,n) mp[d.fa[i]]++;
//	for(std::pair<int,int> p : mp) {
//		ans += p.se * (p.se - 1) / 2;
//	}
//	out << ans << '\n';
//}
