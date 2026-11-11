#include <bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3fLL
#define int long long
#define N 2000005
using namespace std;
int n,d;
int x[N],pre[N];
int cnt[N],sum[N],ans;//数量/步数
void solve(){
	cin >> n >> d;
	ans = 0;
	for (int i = 1,j = 1;i <= n;++i){
		cin >> x[i];
		while (x[i] - x[j] > d) ++j;
		pre[i] = j;
	}
	for (int k = 1;k <= n;++k){
		int tot = k - 1;
		for (int i = 1;i <= n;++i){
			cnt[i] = sum[i] = 0;
		}
		cnt[k] = 1;
		sum[k] = 0;
		for (int i = k + 1;i <= n;++i){
			cnt[i] = 0;
			sum[i] = inf;
			for (int j = max(pre[i],k);j < i;++j) sum[i] = min(sum[i],sum[j]);
			if (pre[i] == i) break;
			tot = i;
			for (int j = pre[i];j < i;++j){
				if (sum[j] == sum[i]) cnt[i] += cnt[j];
			}
			++sum[i];
		}
		for (int i = k;i <= tot;++i) if (cnt[i] == 2) ++ans;
	}
	cout << ans << '\n';
}
signed main(){
	#ifndef HONGXIAODOU
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	#endif
	int C,T;
	cin >> C >> T;
	while (T--) solve();
return 0;
}
