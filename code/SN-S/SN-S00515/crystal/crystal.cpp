// SN-S00515 王铂涵 西安市铁一中
#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fir first
#define sec second
#define pb push_back
#define pq priority_queue
#define ull unsigned long long
#define ll long long
#define rep(i,l,r) for(int i=l;i<=r;i++)
using namespace std;
const int N = 5e5 + 5;

int n, m, a[N];
#define ls(x) ((x)<<1)
#define rs(x) (((x) << 1) | 1)
class Segment_Tree{
	private:
		int t[N << 2], lzy[N << 2];
		void up(int x){t[x] = t[ls(x)] + t[rs(x)];}
		void push(int x, int l, int r, int val){t[x] += val * (r - l + 1); lzy[x] += val;}
		void down(int x, int l, int r){
			if(lzy[x]){
				int mid = ((l + r) >> 1);
				push(ls(x), l, mid, lzy[x]);
				push(rs(x), mid + 1, r, lzy[x]);
				lzy[x] = 0;
			}
		}
	public:
		void modify(int ql, int qr, int val, int x = 1, int l = 1, int r = n){
			if(ql > qr || ql > r || l > qr) return ;
			if(ql <= l && qr >= r) return push(x, l, r, val);
			int mid = ((l + r) >> 1); down(x, l, r);
			modify(ql, qr, val, ls(x), l, mid); modify(ql, qr, val, rs(x), mid + 1, r); up(x);
		}
		int query(int ql, int qr, int x = 1, int l = 1, int r = n){
			if(ql > r || l > qr || ql > qr) return 0;
			if(ql <= l && qr >= r) return t[x];
			int mid = ((l + r) >> 1); down(x, l, r);
			return query(ql, qr, ls(x), l, mid) + query(ql, qr, rs(x), mid + 1, r);
		}
} tr;
void solve(){
	cin >> n >> m; rep(i,1,n) cin >> a[i]; sort(a + 1, a + n + 1);
	int l = 1, res = 0;
	rep(r, 1, n){
		tr.modify(1, r - 1, a[r] - a[r - 1]);
		while(tr.query(l, r - 1) > m) ++l;
		res = max(res, r - l + 1);
	} cout << res << "\n";
}
signed main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int T = 1;
//	cin >> T;
	while(T--) solve();
}
/*线段树一遍过怎么说*/
