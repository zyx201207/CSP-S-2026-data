#include<bits/stdc++.h>
using namespace std;
long long c,n,t,d,ans;
long long a[2000006],dp[2000006],vis[2000006];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    if(c==11||c==12){
        while(t--){
            cin>>n>>d;
            for(int i=1;i<=n;i++){
                cin>>a[i];
            }
            long long x=a[2]-a[1];
            long long xx=d/x;
            if(xx<2){
                cout<<"0\n";
                continue;
            }
            if(n<2*xx){
                cout<<"0\n";
                continue;
            }

            cout<<n-2*xx+1<<endl;
        }
        return 0;
    }
    while(t--){
        ans=0;
        scanf("%lld%lld",&n,&d);
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=n;j++)dp[j]=3e18+1;
            for(int j=0;j<=n;j++)vis[j]=1;
            dp[i]=0;
            for(int j=i;j<n;j++){
                for(int k=j+1;k<=n&&a[k]-a[j]<=d;k++){
                    if(dp[k]==dp[j]+1){
                        vis[k]+=vis[j];
                    }
                    else if(dp[k]>dp[j]+1){
                        dp[k]=dp[j]+1;
                        vis[k]=vis[j];
                    }
                }
            }
                for(int k=i;k<=n;k++){
                    if(vis[k]==2){
                        ans++;
                    }
                }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
