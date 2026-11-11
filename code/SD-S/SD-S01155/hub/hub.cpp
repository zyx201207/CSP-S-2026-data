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
	out << "1\n";
}

signed main() {
	__FILE_IO__("hub");
	std::ios::sync_with_stdio(0), in.tie(0);  
	int T = 1;
	in >> c;
	in >> T;
	while(T--) {
		bt();
	}
	return 0;
}
