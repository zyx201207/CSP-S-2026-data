#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f(i,a,b) for(int i=a;i<=b;i++)
#define endl '\n'
const int N=2e6+5;
int c,t,n,d,dp[N];
signed main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin.tie(0)->sync_with_stdio(false);
    cin>>c>>t;
    while(t--) {
        memset(dp,1,sizeof dp);
        cin>>n>>d;
        vector<int> x(n+1);
        f(i,1,n) cin>>x[i];
        f(i,1,n-1) {
            int nxt=lower_bound(x.begin(),x.end(),x[i]+d,greater<int>())-x.begin();
            int tru_st=lower_bound(x.begin(),x.end(),x[nxt]-d)-x.begin();
            int s=0;
            f(m,tru_st,nxt) s+=dp[m];
            dp[nxt]=max(dp[nxt],s);
        }
        cout<<dp[n]<<endl;
    }
    return 0;
}
