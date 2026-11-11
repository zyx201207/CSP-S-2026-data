#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    for(int j=1;j<=t;j++){
        int n,d,a[2000005],dp[2000005],cnt=0;
        cin>>n>>d;
        dp[1]=0;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=2;i<=n;i++)dp[i]=dp[i-1]+(a[i]-a[i-1]);
        for(int i=2;i<=n;i++){
            int q=dp[i];
            if(q%d>0)cnt++;
        }
        cout<<cnt<<endl;
    }
}
