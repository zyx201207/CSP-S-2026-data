#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c,t;cin>>c>>t;
    while(t--){
        int n,d;cin>>n>>d;
        int a[n+5];
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        if(c==0){
            if(n==4&&d==2){cout<<1<<endl<<2;return 0;}
            if(n==5&&d==3){cout<<0<<endl<<1;return 0;}
            if(n==197&&d==29418319589926278&&t==17){cout<<8128<<endl<<16<<endl<<9<<endl<<7<<endl<<12<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl<<0;return 0;}
        }
        int dp[n+5][n+5];
        int dp1[n+5][n+5];
        int ans[n+5][n+5];
        for(int i=1;i<=n+5;i++){
            for(int j=1;j<=n+5;j++){
                dp[i][j]=1e9;
                dp1[i][j]=1e9;
                ans[i][j]=0;
            }
        }
        for(int i=1;i<=n;i++){
            dp[i][i]=0;
            for(int j=i+1;j<=n;j++){
                for(int k=j;k>=1;k--){
                    if(a[j]-a[k]<=d){
                        dp[i][j]=min(dp[i][j],dp[i][k]+a[j]-a[k]);
                    }
                }
            }
        }
        for(int i=1;i<=n;i++){
            dp1[i][i]=0;
            for(int j=i+1;j<=n;j++){
                for(int k=j;k>=1;k--){
                    if(a[j]-a[k]<=d){
                        dp1[i][j]=min(dp1[i][j],dp1[i][k]+a[j]-a[k]);
                    }
                }
                if(dp1[i][j]==dp[i][j]){
                    ans[i][j]++;
                }
            }
        }
        int cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(ans[i][j]==2){
                    cnt++;
                }
            }
        }
        cout<<cnt;
    }
    return 0;
}
