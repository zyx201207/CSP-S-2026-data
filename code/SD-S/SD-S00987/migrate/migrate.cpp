#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,c,n,d,a[2000010];
int check(int l,int r) {
	int p = 0,s = 0;
	for (int i = l + 1; i <= r; ++i) {
		if (s + a[i] - a[i - 1] <= d) s += a[i] - a[i - 1];
		else s = a[i] - a[i - 1],++p;
	}
	if (s) ++p;
	return p;
}
int dfs(int idx,int lst,int now,int ans,int end) {
	if (now > ans) return 0;
	if (idx == end + 1) {
//		printf("!!!!!!%lld,%lld,%lld,%lld,%lld\n",idx,lst,now,ans,end);
		return 1;
	}
	if (a[idx] - a[lst] > d) return 0;
//	printf("!%lld,%lld,%lld,%lld,%lld\n",idx,lst,now,ans,end);
	return dfs(idx + 1,lst,now,ans,end) +
	       dfs(idx + 1,idx,now + 1,ans,end);
}
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> c >> T;
	while (T--) {
		cin >> n >> d;
		for (int i = 1; i <= n; ++i) cin >> a[i];
		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = i + 3; j <= n; ++j) {
//				printf("%lld,%lld %lld,%lld\n",i,j,check(i,j),dfs(i,i,1,check(i,j),j));
				if (dfs(i,i,1,check(i,j),j) == 2) ++ans;
			}
		}
		cout << ans << endl;
	}
	return 0;
}

