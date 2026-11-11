#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10,inf=1e18;
int n,d,a[N],ans;
struct node{
    int v,s;
}dp[N];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int c,T;cin>>c>>T;
    while(T--){
        cin>>n>>d;
        ans=0;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)dp[j]={inf,0};
            dp[i]={0,1};
            for(int j=i+1;j<=n;j++){
                for(int k=j-1;k>=i;k--){
                    if(a[j]-a[k]>d)break;
                    if(dp[j].v==dp[k].v+1)dp[j].s+=dp[k].s;
                    if(dp[j].v>dp[k].v+1){
						dp[j].v=dp[k].v+1;
						dp[j].s=dp[k].s;
					}
                }
            }
            for(int j=1;j<=n;j++)
                if(dp[j].s==2)ans++;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
