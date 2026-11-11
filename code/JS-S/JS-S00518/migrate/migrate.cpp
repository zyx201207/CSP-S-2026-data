#include<bits/stdc++.h>
using namespace std;

#define int long long

int dp[5005][5005],ds[5005][5005],x[2000006];

signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int c,t;cin>>c>>t;
    while(t--){
        int n,d,ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }

        for(int i=1;i<=5000;i++){
            for(int j=1;j<=5000;j++){
                ds[i][j]=1e18;
                if(i==j) ds[i][j]=0;
            }
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j+i<=n;j++){
                if(x[j+i]-x[j]<=d) dp[j][j+i]=1,ds[j][j+i]=1;
                else{
                    int dsmin=1e18,cnt=0;
                    for(int k=j+1;k<i;k++){
                        if(ds[j][j+k]+ds[j+k][j+i]<dsmin){
                            dsmin=ds[j][j+k]+ds[j+k][j+i];
                            cnt=1;
                        }
                        if(ds[j][j+k]+ds[j+k][j+i]==dsmin) cnt++;
                    }
                    if(cnt==2){
                        ans++;
                        dp[j][j+i]=2;
                    }
                    else break;
                }
            }
        }
        cout<<ans<<'\n';
    }

    return 0;

}
