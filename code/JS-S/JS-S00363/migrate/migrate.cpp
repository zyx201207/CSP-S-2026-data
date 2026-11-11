#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp1[5005][5005];//i->j min distant
int dp2[5005][5005];
int a[5005];
int n,d;
int T,c;
int ans;
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while(T--){
        cin>>n>>d;
        memset(dp2,0,sizeof(dp2));
        ans=0;
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dp1[i][j]=1e18;
            }
        }
        for(int i=1;i<=n;i++) dp1[i][i]=1;
        for(int len=1;len<=n-1;len++){
            for(int i=1;i<=n-len;i++){
                int j=i+len;
                if(a[j]-a[i]<=d){
                    dp1[i][j]=1;
                }
                else{
                    for(int k=i;k<=j;k++){

                        dp1[i][j]=min(dp1[i][k]+dp1[k][j]+1,dp1[i][j]);
                    }
                }
            }
        }
        for(int len=1;len<=n-1;len++){
            for(int i=1;i<=n-len;i++){
                int j=i+len;
                if(a[j]-a[i]>d){
                    for(int k=i;k<=j;k++){
                        if(dp1[i][k]+dp1[k][j]+1==dp1[i][j]){
                            dp2[i][j]++;
                        }
                    }
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(dp2[i][j]==2){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }


}
