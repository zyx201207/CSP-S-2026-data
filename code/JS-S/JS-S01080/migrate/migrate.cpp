#include <bits/stdc++.h>
using namespace std;

long long c,t,n,d;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    while(t--){
        cin >> n >> d;
        long long a[n+5],dp[n+5],l[n+5];
        long long ans=0;
        for (long long i=1;i<=n;i++)
            cin >> a[i];
        for (long long i=1;i<=n;i++){
            for (long long j=1;j<=n;j++){
                l[j]=n+10;
                dp[j]=1;
            }
            l[i]=1;
            for (long long j=i;j<=n;j++){
                for (long long k=j;a[j]-a[k]<=d&&k>=i;k--){
                    if(l[j]>l[k]+1){
                        l[j]=l[k]+1;
                        dp[j]=dp[k];
                    }else if(l[j]==l[k]+1){
                        dp[j]+=dp[k];
                    }
                }
                if (dp[j]==2)
                    ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}