#include <bits/stdc++.h>
#define int long long
using namespace std;

int c,T,n,d;
int a[200005],nxt[200005],can[200005];

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0); 
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> T;
	while(T--) {
		int ans = 0;
		cin >> n >> d;
		for(int i = 1; i <= n; i++) cin >> a[i];
		int ok = n+1;
		for(int i = 1; i <= n; i++) {
			memset(nxt,0,sizeof(nxt));
			memset(can,0,sizeof(can));
			int cnt = 0,pos = i;
			for(int j = i+1; j <= n; j++) {
				if(a[j] - a[pos] > d) {
					pos = j-1;
					nxt[++cnt] = j-1;
					if(a[j] - a[j-1] > d) {
						ok = j;
						break;
					}
				}
			}
			can[1] = 1;
			for(int j = 2; j <= cnt; j++) {
				if(a[nxt[j]]-a[nxt[j-1]-1] <= d) {
					if(a[nxt[j]]-a[nxt[j-1]-2] <= d) {
						can[j] == 3;
						break;
					}
					else {
						can[j] = can[j-1] + 1;
						if(can[j] == 3) break;
					}
				}
				else {
					can[j] = can[j-1];
				}
			}
			nxt[cnt+1] = n+1;
			for(int j = 1; j <= cnt; j++) {
				if(can[j] == 3) break;
				if(can[j] == 2) ans++;
				for(int k = nxt[j]+1; k <= nxt[j+1]-1; k++) {
					if(can[j] == 2) {
						if(a[k] - a[nxt[j]-1] > d && a[k] - a[nxt[j]] <= d) ans++;
					}
					else {
						if(a[k] - a[nxt[j]-1] <= d && a[k] - a[nxt[j]-2] > d) ans++;
					}
				}
			}
		}
		cout << ans << '\n';
	}
}
