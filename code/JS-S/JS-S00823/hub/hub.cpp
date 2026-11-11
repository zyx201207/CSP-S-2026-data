#include <bits/stdc++.h>
using namespace std;
const int N=1e6+3;
int n,k,vis[N],bk[N],dep[N],d[N];
vector<int>v[N];
void dfs(int x,int f){
    for(auto y:v[x])if(y^f){
        dep[y]=dep[x]+1;
        dfs(y,x);
    }
}
void dfs2(int x,int f){
    bk[x]=1;
    for(auto y:v[x])if(vis[y]&&y^f){
        dfs2(y,x);
    }
}
int get(){
    int res=0;
    for(int i=1;i<=n;i++) d[i]=n;
    for(int i=1;i<=n;i++)if(vis[i]){
        dep[i]=0;dfs(i,0);
        for(int j=1;j<=n;j++)if(!vis[j]) d[j]=min(d[j],dep[j]);
    }
    for(int i=1;i<=n;i++)if(!vis[i]) res=max(res,d[i]);
    return res;
}
namespace T1{
    void solve(){
        for(int i=1;i<=n;i++) vis[i]=0;
        int ans=n;
        for(int i=1;i<=n;i++){
            vis[i-1]=0,vis[i]=1;
            for(int j=i+1;j<=n;j++){
                if(j-1!=i) vis[j-1]=0;
                else vis[n]=0;
                vis[j]=1;
                ans=min(ans,get());
            }
        }
        cout<<ans<<"\n";
    }
}
void mainb(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) v[i].clear();
    for(int i=1,x,y;i<n;i++) cin>>x>>y,v[x].push_back(y),v[y].push_back(x);
    int ans=n;
    if(n==2){ return cout<<"0\n",void(); }
    if(k==2) return T1::solve(),void();
    for(int S=1;S<(1<<n);S++){
        if(__builtin_popcount(S)!=k) continue;
        for(int i=1;i<=n;i++) vis[i]=bk[i]=0;
        for(int i=1;i<=n;i++) if(S&(1<<i-1)) vis[i]=1;
        int cc=0;
        for(int i=1;i<=n;i++) if(vis[i]&&!bk[i]) cc++,dfs2(i,0);
        if(cc>2) continue;
        ans=min(ans,get());
    }
    cout<<ans<<"\n";
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int test,T;cin>>test>>T;
    while(T--) mainb();
}
