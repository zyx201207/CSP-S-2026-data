#include<bits/stdc++.h>
#define int long long
#define inf 1e18
using namespace std;
const int N = 500005;
int n, m, s = 0, bas = 0, ans = 1;
vector<int>a(N);
bool check() {
	for (int i = 1; i <= n; i++) {
		if (a[i] != i) return false;
	}
	return true;
}
namespace sol1 {
	void solve() {
		int mid=n/2+1;
		vector<int>sum(n+1);
		int pl=0,l=mid-1;
		for(int i=1;i<=mid;i++){
			sum[i]=sum[i-1]+a[mid]-a[mid-i];
		}
		for(int i=1;i<=l;i++) cout<<sum[i]<<' ';
		for(int i=1;i<=mid-1;i++){
			if(sum[i]*2>m) pl=i;
		}
		int cnt=1;
		cnt+=(mid-pl+1)*2;
		cout<<pl;
		m-=sum[pl-1]*2;
		if(m>a[mid]-a[pl+1]) cnt++;
		cout<<cnt;
	}
}
namespace sol2 {
	struct node {
		int v, id;
	} c[N];
	bool cmp(node x, node y) {
		if (x.v == y.v) return x.id < y.id;
		return x.v < y.v;
	}
	void solve() {
		for (int i = 1; i <= n; i++) {
			s += a[i];
			c[i].v = a[i];
			c[i].id = i;
		}
		s += m;
		bas = s / n;
		int pl = 0, pl1 = 0, del = inf;
		for (int i = 1; i <= n; i++) {
			if (abs(a[i] - bas) < del) {
				del = abs(a[i] - bas);
				pl = i;
			}
		}
		sort(c + 1, c + 1 + n, cmp);
		for (int i = 1; i <= n; i++) {
			if (c[i].id == pl) pl1 = i;
		}
		vector<int>chf(n + 1);
		for (int i = 1; i < pl1; i++) {
			chf[i] = abs(c[pl1].v - c[i].v);
		}
		for (int i = pl1 + 1; i <= n; i++) {
			chf[i] = abs(c[i].v - c[pl1].v);
		}
//	for(int i=1;i<=n;i++) cout<<chf[i]<<' ';
		sort(chf.begin() + 1, chf.end());
		for (int i = 1; i <= n; i++) cout << chf[i] << ' ';
		for (int i = 2; i <= n; i++) {
			if (m - chf[i] >= 0) {
				m = m - chf[i];
				ans++;
			}
			if (m < 0) break;
		}
		cout << ans;
	}
}
inline void solve() {
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(check()) sol1::solve();
	else sol2::solve();
}
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T = 1;
//	cin>>T;
	while (T--) solve();
	return 0;
}