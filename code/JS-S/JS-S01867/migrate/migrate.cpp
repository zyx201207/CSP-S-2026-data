#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,T;
int main(){
    ios::sync_with_stdio(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while(T--){
        int n,ans=0;
        ll d,a[305]={0},dp[305][305],cnt[305][305]={0};
        cin>>n>>d;
        memset(dp,0x3f,sizeof(dp));
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        if(c==11||c==12){
            ans=n-(d/(a[2]-a[1])*2-1);
            if(ans<0) ans=0;
            cout<<ans<<'\n';
        }
        else{
            for(int len=2;len<=n;len++){
                for(int l=1;l+len-1<=n;l++){
                    int r=l+len-1;
                    if(a[r]-a[l]<=d){
                        dp[l][r]=1;
                        cnt[l][r]=1;
                        continue;
                    }
                    for(int i=l+1;i<r;i++) dp[l][r]=min(dp[l][r],dp[l][i]+dp[i][r]);
                    for(int i=l+1;i<r;i++){
                        if(a[r]-a[i]<=d&&dp[l][i]+1==dp[l][r]){
                            cnt[l][r]+=cnt[l][i];
                        }
                }
                }
            }
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    //printf("%lld ",dp[i][j]);
                    if(cnt[i][j]==2){
                        ans++;
                        //printf("%d %d\n",i,j);
                    }
                }
                //printf("\n");
            }
            cout<<ans<<'\n';
        }
    }
    return 0;
}