#include <bits/stdc++.h>
using namespace std;
#define int long long
//final
int a[200005];
int dp[200006];
signed main () {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while (t--) {
        int n,d;
        cin>>n>>d;
        memset(a,0,sizeof(a));
        for (int i=1;i<=n;i++) {
            cin>>a[i];
        }
        dp[1]=0;
        for (int i=2;i<=n;i++) {
            for (int j=1;j<=d;j++) {
                if (i-j>=1) dp[i]=dp[i-j]+1;
            }
        }
        int cnt=0;
        for (int i=1;i<=n;i++) {
            if (dp[i]==2) cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
