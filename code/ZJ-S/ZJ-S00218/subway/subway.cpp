#include<bits/stdc++.h>
using namespace std;
namespace zhr{
#define AK 0
#define int long long
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define i128 __int128
#define vi vector<int>
#define vp vector<pair<int,int> >
#define pii pair<int, int>
#define mkp make_pair
#define up(l,r,i) for(int i=l;i<=r;++i)
#define dn(r,l,i) for(int i=r;i>=l;--i)
#define ctn continue
#define brk break
#define mems(a,x) memset((a),(x),sizeof(a))
#define De(x) cout<<#x<<": "<<x<<' '
#define D(x) cout<<#x<<": "<<x<<'\n'
#define eb emplace_back
#define pb push_back
#define _all(x) x.begin(),x.end()
#define _sz(x) ((int)(x.size()))
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
inline void ckmin(int &x, int y){x = x < y ? x : y;}
inline void ckmax(int &x, int y){x = x > y ? x : y;}
}
using namespace zhr;
const int N = 5e5 + 7, mod = 1e9 + 7;
int Tc, n, m, d, Q;
int a[N];
int w[N];
vp vc[N];
int f[507][507];
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> Tc >> n >> m >> d >> Q;
	up(1, m, i) cin >> w[i];
	up(1, n, i){
		int k, x, y;cin >> k;
		while(k--){
			cin >> x >> y;
			vc[x].eb(i, y);
		}
	}
	mems(f, 0x3f);
	up(1, n, i) f[i][i] = 0;
	up(1, m, i){
		up(0, _sz(vc[i]) - 1, j){
			up(j + 1, _sz(vc[i]) - 1, k){
				ckmin(f[vc[i][j].first][vc[i][k].first], vc[i][j].second + vc[i][k].second);
				ckmin(f[vc[i][k].first][vc[i][j].first], vc[i][j].second + vc[i][k].second);
			}
		}
	}
	up(1, n, k) up(1, n, i) up(1, n, j) ckmin(f[i][j], f[i][k] + f[k][j]); 
	while(Q--){
		int x, y;cin >> x >> y;
		int ans = infll;
		for(pii u : vc[x]) for(pii v : vc[y]){
			ckmin(ans, u.second + v.second + f[u.first][v.first]);
		}
		cout << ans + w[x] + w[y] << '\n'; 
	}
	return AK;
}
/*
 
*/
