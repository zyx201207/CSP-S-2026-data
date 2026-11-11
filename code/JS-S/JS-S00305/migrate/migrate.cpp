#include<bits/stdc++.h>
#define int long long
#define MAXN 2000005
using namespace std;
int c,t;
int n,d;
int x[MAXN];
int dp[MAXN];
int cnt[MAXN];
int ans;
signed main(){
    cin.tie(0),cout.tie(0);
    ios::sync_with_stdio(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while (t--){
        cin>>n>>d;
        for (int i=1;i<=n;i++){
            cin>>x[i];
        }
        ans=0;
        if (13<=c&&c<=14){
            for (int i=1;i<=n;i++){
                int p=lower_bound(x+1,x+n+1,x[i]+d)-x;
                if (p+1<=n&&p-i==2) ans++;
            }
            cout<<ans;
            continue;
        }
        for (int i=1;i<=n;i++){
            memset(dp,0,sizeof(dp));
            memset(cnt,0,sizeof(cnt));
            dp[i]=1;
            for (int j=i+1;j<=n;j++){
                int p=lower_bound(x+1,x+n+1,x[j]-d)-x;
                cnt[j]=cnt[p]+1;
                for (;p<j;p++){
                    if (cnt[p]==cnt[j]) continue;
                    dp[j]+=dp[p];
                    if (dp[j]>2) break;
                }
                if (dp[j]==2) ans++;
            }
        }
        cout<<ans<<'\n';
    }

    return 0;

}
