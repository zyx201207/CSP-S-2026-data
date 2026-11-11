#include<bits/stdc++.h>
using namespace std;
long long c,T;
long long n,d;
long long x[2000005];
long long dp[2000005];

int main(){
    freopen("migrate3.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>T;
    while(T--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        for(int i=2;i<=n;i++){
            if(x[i]-x[i-1]>d)n=i-1;
        }
        int h=x[2]-x[1];
        bool flag=0;
        for(int i=2;i<=n;i++){
            if(x[i]-x[i-1]!=h){
                flag=1;
            }
        }
        if(flag==0){
            int k=d/h;
            if(k==2){
                if(n<4)cout<<0<<'\n';
                else{
                    long long k=1;
                    for(int i=5;i<=n;i++){
                        k*=2;
                    }
                    cout<<k<<'\n';
                }
            }else{
                cout<<0<<'\n';
            }
        }else{
            long long ans=0;
            for(int i=1;i<=n;i++){
                for(int j=i;j<=n;j++){
                    for(int k=i-1;k>=i-d;k--){
                        if(dp[k]+d>=dp[j])dp[j]=min(dp[j],dp[k])+1;
                    }
                    for(int k=i-1;k>=i-d;k--){
                        if(dp[k]+d>=dp[j])if(dp[k]==dp[j-1])ans++;
                    }
                }
            }
            cout<<ans<<"\n";
        }
    }
    return 0;
}
/*
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989


*/
