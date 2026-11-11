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
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
inline void ckmin(int &x, int y){x = x < y ? x : y;}
inline void ckmax(int &x, int y){x = x > y ? x : y;}
}
using namespace zhr;
const int N = 5e5 + 7, mod = 1e9 + 7;
int n, m;
int a[N];
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	up(1, n, i) cin >> a[i];
	sort(a + 1, a + 1 + n);
	int sum = 0, j = 1, ans = 0;
	up(1, n, i){
		sum += (a[i] - a[i - 1]) * (i - j);
		while(sum > m){
			sum -= a[i] - a[j++];
		}
		ckmax(ans, i - j + 1);
	}
	cout << ans << '\n';
	return AK;
}
