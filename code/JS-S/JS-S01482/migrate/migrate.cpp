#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[301][301];
ll x[301],cnt[301][301];
inline void solve(){
    memset(dp,0x3f,sizeof(dp));
    memset(cnt,0,sizeof(cnt));
    int n;
    ll d;
    cin>>n>>d;
    for(int i=1;i<=n;++i){
        cin>>x[i];
    }
    for(int ptr,i=1;i<=n;++i){
        dp[i][i]=0;cnt[i][i]=1;
        ptr=i-1;
        while(ptr>=1&&x[i]-x[ptr]<=d){
            dp[i][ptr]=dp[ptr][i]=cnt[i][ptr]=cnt[ptr][i]=1;
            --ptr;
        }
        ptr=i+1;
        while(ptr<=n&&x[ptr]-x[i]<=d){
            dp[i][ptr]=dp[ptr][i]=cnt[i][ptr]=cnt[ptr][i]=1;
            ++ptr;
        }
    }
    for(int k=1;k<=n;++k){
        for(int u=1;u<=n;++u){
            for(int v=1;v<=n;++v){
                if(u==v||u==k||v==k)continue;
                if(dp[u][v]==dp[u][k]+dp[k][v]){
                    //cout<<u<<"->"<<v<<" can use "<<u<<"->"<<k<<" and "<<k<<"->"<<v<<'\n';
                    cnt[u][v]+=(cnt[u][k]*cnt[k][v]);
                }
                else if(dp[u][v]>dp[u][k]+dp[k][v]){
                    //cout<<u<<"->"<<v<<" is now updated to "<<u<<"->"<<k<<" and "<<k<<"->"<<v<<'\n';
                    dp[u][v]=dp[u][k]+dp[k][v];
                    cnt[u][v]=cnt[u][k]*cnt[k][v];
                }
            }
        }
    }
    /*
    for(int u=1;u<=n;++u){
        for(int v=1;v<=n;++v){
            cout<<cnt[u][v]<<' ';
        }
        cout<<'\n';
    }
    */
    int sum=0;
    for(int u=1;u<=n;++u){
        for(int v=1;v<=n;++v){
            if(cnt[u][v]==2)++sum;
        }
    }
    cout<<(sum>>1)<<'\n';
    
}
int main(){
    #ifndef testing
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    #endif
    int c,t;
    cin>>c>>t;
    ++t;
    while(--t){
        solve();
    }
    return 0;
}