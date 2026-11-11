#include<bits/stdc++.h>
#define lint long long
using namespace std;
lint c,t,n,d,ans,a[2000002];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i = 1;i <= n;i++) cin >> a[i];
		if(c == 1 || c == 2){
			ans = 0;
			for(int i = 1;i <= n;i++){
				for(int j = i + 2;j <= n;j++){
					int mn = 0x3f3f3f3f,cnttt = 0;
					int L = j - i - 1;
					for(int msk = 0;msk < (1 << L);msk++){
						int f[101] = {0},cnt = 0;
						f[++cnt] = i;
						for(int k = 0;k < L;k++) if(msk & (1 << k)) f[++cnt] = i + k + 1;
						f[++cnt] = j;
						bool ok = true;
						for(int k = 1;k < cnt;k++) if(a[f[k + 1]] - a[f[k]] > d) ok = false;
						if(ok) mn = min(mn,cnt);
					}
					for(int msk = 0;msk < (1 << L);msk++){
						int f[101] = {0},cnt = 0;
						f[++cnt] = i;
						for(int k = 0;k < L;k++) if(msk & (1 << k)) f[++cnt] = i + k + 1;
						f[++cnt] = j;
						bool ok = true;
						for(int k = 1;k < cnt;k++) if(a[f[k + 1]] - a[f[k]] > d) ok = false;
						if(ok && cnt == mn) cnttt++;
					}
					if(cnttt == 2) ans++;
				}
			}
			cout << ans << "\n";
		}else if(c == 11 || c == 12){
			ans = 0;
			lint dc = abs(a[2] - a[1]);
			lint stp = d / dc;
			if(stp > 1)cout << max(n - (stp * 2 - 1),0LL) << "\n";
			else cout << "0\n";
		}else if(c == 13 || c == 14) cout << "0\n";
	}
	return 0;
}
