#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
int n,m;
ll a[N],dp[N],sum[N];
bool vis[N];
ll ans=0;
void dfs(int pos,int cnt){
    if(pos==n+1){
        if(cnt==m){
            ll res=0;
            int flag=0;
            for(int i=1;i<=n;i++){
                if(vis[i]){
                    if(!flag){
                        res=a[i];
                        flag=1;
                    }
                    else res=(res&a[i]);
                }
            }
            ans=max(res,ans);
            return ;
        }
        else return ;
    }

    vis[pos]=1;
    dfs(pos+1,cnt+1);
    vis[pos]=0;
    dfs(pos+1,cnt);
}
signed main(){
    freopen("and,in","r",stdin);
    freopen("and,out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=20){
        dfs(1,0);
        cout<<ans;
        return 0;
    }
    else{
        ans=-1;
        for(int i=1;i<=n;i++){
            ll res=a[i];
            ll cnt=0;
            for(int j=m;j>=0;){
                if(j-1>=0){
                    dp[i]=max(dp[i-1],dp[i-1]&a[i]);
                }
            }
        }
        for(int i=1;i<=n;i++){
            ans=max(ans,dp[i]);
        }
        cout<<ans;
    }

    return 0;
}
