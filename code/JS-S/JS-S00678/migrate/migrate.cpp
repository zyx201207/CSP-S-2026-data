#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,x[2000006],dp[2000006];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        int ans=0;
        cin>>n>>d;
        int br=n+1;
        for(int i=1;i<=n;i++){
            dp[i]=0;
            cin>>x[i];
            if(x[i]-x[i-1]>d){
                br=i;
            }
        }
        for(int i=1;i<br;i++){
            dp[i]=1;
            for(int j=i+1;j<br;j++){
                int cnt=1;
                while(j-cnt>=i&&d>=x[j]-x[j-cnt]){
                    dp[j]+=dp[j-cnt];
                    cnt++;
                }
                if(dp[j]==2){
                    ans++;
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
