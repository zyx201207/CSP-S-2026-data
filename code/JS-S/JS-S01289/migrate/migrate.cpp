#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2000005;
int a[N],nxt[N];
int dp[N][3][2];//how many routes from i,ways = 1/2, 0 <- include (i,nxt_nxt_i],1 <- not include (i,nxt_nxt_i]
signed main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int c,T; cin >> c >> T;
    for(int te=1;te<=T;++te) {
        int n,d; cin >> n >> d;
        for(int i=1;i<=n;++i) cin >> a[i];
        for(int i=1;i<=n;++i)
            for(int j=1;j<=2;++j)
                for(int k=0;k<=1;++k) dp[i][j][k]=0;
        int Nxt=1;
        for(int i=1;i<=n;++i) {
            while(Nxt<n && a[Nxt+1]-a[i]<=d) ++Nxt;
            nxt[i]=Nxt;
        }
        // for(int i=1;i<=n;++i) cout << nxt[i] << " "; cout << "\n";
        int ans=0;
        for(int i=n;i>=1;--i) {
            if(nxt[i]==i) continue;
            if(nxt[i]==i+1) {
                dp[i][1][0]=dp[i+1][1][0]+1;
                dp[i][2][0]=dp[i+1][2][0];
                dp[i][1][1]=dp[i+1][1][0]-(nxt[i+1]-(i+1));
                dp[i][2][1]=dp[i+1][2][0];
            }
            else {
                int tri=nxt[i]-2;
                int cub=nxt[i]-1;
                //(i,nxt_i]
                dp[i][1][0]=nxt[i]-i;
                //(nxt_i,nxt_nxt_i]
                tri=nxt[tri]; cub=nxt[cub];
                dp[i][1][0]+=nxt[nxt[i]]-cub;
                dp[i][2][0]+=cub-tri;
                if(cub==nxt[nxt[i]] && tri==nxt[nxt[i]]) {
                    // cout << i << " " << dp[i][1][0] << " " << dp[i][2][0] << " " << dp[i][1][1] << " " << dp[i][2][1] << "\n";
                    ans+=dp[i][2][0];
                    continue;
                }
                else if(cub==nxt[nxt[i]]) {
                    dp[i][2][0]+=dp[nxt[i]][1][0]-(nxt[nxt[i]]-nxt[i]);
                    dp[i][2][1]+=dp[nxt[i]][1][0]-(nxt[nxt[i]]-nxt[i]);
                    // cout << i << " " << dp[i][1][0] << " " << dp[i][2][0] << " " << dp[i][1][1] << " " << dp[i][2][1] << "\n";
                    ans+=dp[i][2][0];
                    continue;
                }
                // cout << "test 1 : " << cub << " " << tri << " " << dp[i][1][0] << " " << dp[i][2][0] << " " << dp[i][1][1] << " " << dp[i][2][1] << "\n";
                //(nxt_nxt_i,nxt_nxt_nxt_i]
                tri=nxt[tri]; cub=nxt[cub];
                //look at nxt[i]
                //(cub,nxt_nxt_nxt_i]
                if(nxt[nxt[i]]==nxt[i]) {
                    // cout << i << " " << dp[i][1][0] << " " << dp[i][2][0] << " " << dp[i][1][1] << " " << dp[i][2][1] << "\n";
                    ans+=dp[i][2][0];
                    continue;
                }
                // cout << "test 2 : " << cub << " " << tri << " " << dp[i][1][0] << " " << dp[i][2][0] << " " << dp[i][1][1] << " " << dp[i][2][1] << "\n";
                int nxtcub=nxt[nxt[nxt[i]]-1];
                int nxttri=nxt[nxt[nxt[i]]-2];
                nxtcub=max(nxtcub,cub);
                nxttri=max(nxttri,cub);
                dp[i][1][0]+=nxt[nxt[nxt[i]]]-nxtcub;
                dp[i][2][0]+=nxtcub-nxttri;
                dp[i][1][1]+=nxt[nxt[nxt[i]]]-nxtcub;
                dp[i][2][1]+=nxtcub-nxttri;
                if(cub==nxt[nxt[nxt[i]]]) {
                    // cout << i << " " << dp[i][1][0] << " " << dp[i][2][0] << " " << dp[i][1][1] << " " << dp[i][2][1] << "\n";
                    ans+=dp[i][2][0];
                    continue;
                }
                dp[i][1][0]+=dp[nxt[i]][1][1];
                dp[i][2][0]+=dp[nxt[i]][2][1];
                dp[i][1][1]+=dp[nxt[i]][1][1];
                dp[i][2][1]+=dp[nxt[i]][2][1];
            }
            // cout << i << " " << dp[i][1][0] << " " << dp[i][2][0] << " " << dp[i][1][1] << " " << dp[i][2][1] << "\n";
            ans+=dp[i][2][0];
        }
        cout << ans << "\n";
    }
    return 0;
}