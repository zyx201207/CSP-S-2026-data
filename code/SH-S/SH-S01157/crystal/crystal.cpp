#include<bits/stdc++.h>
#define max_eq(x,y) (x)=max((x),(y))
#define min_eq(x,y) (x)=min((x),(y))
#define eb emplace_back
#define em emplace
#define mkp make_pair
#define fi first
#define se second
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vint;
typedef vector<ll> vll;
// 天天说要被单调队列了，你会写单调队列吗？不过这里只是手写队列。 
constexpr int N=5e5+5;
int n, m, a[N], q[N];

signed main() {
	freopen("crystal.in", "r", stdin); // 大样例有点水， 
	freopen("crystal.out", "w", stdout); // 后面对拍一下。 
	cin.tie(nullptr); cout.tie(nullptr);
	ios::sync_with_stdio(false);
	
	cin >> n >> m;
	for (int i=1; i<=n; i++) cin >> a[i];
	sort(a+1, a+n+1);
	int res=0, ans=0; int hd=0, tl=0;
	for (int i=1; i<=n; i++) {
		if (tl>hd) res += (a[i]-q[tl-1])*(tl-hd);
		q[tl++]=a[i];
		if (res>m) {
			while (tl>hd&&res>m) res-=a[i]-q[hd], hd++;
		}
		max_eq(ans, tl-hd);
	}
	cout << ans;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

crystal.4: sol(71) 时取到 315275 
*/
