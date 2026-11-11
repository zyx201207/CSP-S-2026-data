#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,D,ans;
int a[2000005],dp[2000005],q[2000005];
void init(){
    ans=0;
    for(int i=1;i<=n;i++){
        q[i]=0;
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,T;
    cin>>c>>T;
    while(T--){
        cin>>n>>D;
        init();
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<n;i++){
            for(int j=i;j<=n;j++){
                dp[j]=0;
            }
            int h=1,t=1;
            q[1]=i;
            for(int j=i+1;j<=n;j++){
                while(h<=t&&a[j]-a[q[h]]>D){
                    h++;
                }
                if(h>t){
                    dp[j]=0;
                    q[++t]=j;
                    continue;
                }
                dp[j]=dp[q[h]]+1;
                if(h<=t-1&&dp[q[h]]==dp[q[h+1]]&&(h==t-1||dp[q[h+1]]!=dp[q[h+2]])){
                    ans++;
                }
                q[++t]=j;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
