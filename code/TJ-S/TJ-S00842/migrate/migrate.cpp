#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,d,a[2000005],cnt[2000005],nxt[2000005];
int L[2000005],f[2000005];
void solve(){
	cin >> n >> d;
	for (int i = 1;i <= n;++i) cin >> a[i];
	for (int i = 1;i <= n;++i){
		int l = i + 1,r = n,ans = -1;
		while (l <= r){
			int mid = l + r >> 1;
			if (a[mid] - a[i] > d) r = mid - 1;
			else l = mid + 1, ans = mid;
		}
		nxt[i] = ans;
	}
//	for (int i = 1;i <= n;++i) cerr << nxt[i] << ' '; cerr << '\n';
	int ans = 0;
	for (int j = n;j > 1;--j){
//		cerr << j << " ---------------- \n"; 
		for (int i = 1;i <= n;++i) cnt[i] = 0, f[i] = 0;
		for (int i = j - 1;i >= 1;--i){
			if (nxt[i] == -1) break;
			cnt[i] = cnt[nxt[i]] + 1;
			L[cnt[i]] = i;
			if (cnt[i] == 1){
				f[i] = 1;
				continue;
			}
			if (nxt[i] > L[cnt[nxt[i]]] + 1){
				f[i] = 3;
				continue;
			}
			for (int k = L[cnt[nxt[i]]];k <= nxt[i];++k)
				f[i] += f[k];
			ans += (f[i] == 2);
//			cerr << "  " << i << ' ' << f[i] << ' ' << (f[i] == 2) << '\n';
		}
//		for (int i = 1;i <= j;++i) cerr << cnt[i] << ' '; cerr << '\n';
//		for (int i = 1;i <= j;++i) cerr << f[i] << ' '; cerr << '\n';
	}
	cout << ans << '\n';
}

signed main(){
	cin.tie(0) -> ios::sync_with_stdio(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int TST,T; cin >> TST >> T;
	while (T--) solve();
}
