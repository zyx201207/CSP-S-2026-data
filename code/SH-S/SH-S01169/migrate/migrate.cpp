#include<bits/stdc++.h>
#define int long long

using namespace std;
const int N=5005;
int c, t, a[N], s[N][N], cnt[N][N], p[N][N];
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migerate.out", "w", stdout);
	cin >> c >> t;
	while(t--){
		memset(cnt, 0, sizeof cnt); memset(s, 0x3f, sizeof s); memset(p, 1, sizeof p);
		int n,d,ans=0; cin >> n >> d;
		for(int i=1; i<n; i++) s[i][i+1]=1, cnt[i][i+1]=1;
		for(int i=1; i<=n; i++) cin >> a[i];
		for(int len=2; len<=n; len++){
			for(int l=1; l+len-1<=n; l++){
				int r=l+len-1;
				if(a[r]-a[l]<=d) s[l][r]=1, cnt[l][r]=1;
				else{
					for(int k=l+1; k<r; k++){
						if(s[l][k]+s[k][r]<s[l][r]) cnt[l][r]=cnt[l][k]*cnt[k][r], s[l][r]=s[k][r]+s[l][k], p[l][r]=1;
						else if(s[l][k]+s[k][r]==s[l][r]){
							p[l][r]++; if(p[l][r]>=s[l][r]) cnt[l][r]+=cnt[l][k]*cnt[k][r];
						}
						else continue;
					}
				}
				if(cnt[l][r]==2) ans++;
			}
		}
		cout << ans << '\n';
	}
}
