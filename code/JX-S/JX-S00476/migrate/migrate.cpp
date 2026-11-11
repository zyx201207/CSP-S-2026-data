#include<bits/stdc++.h>
using namespace std;
#define int long long
int inline read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();};
    while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();};
    return x*f;
}
const int N=2e6+10;
int c,t;
int x[N],dis[N],n,d,fangan[N],dis_[N],vis[N];
void solve(){
    n=read(),d=read();
    for(int i=1;i<=n;i++)x[i]=read();
    int ans=0;
    for(int start=1;start<n;start++){
        for(int i=1;i<=n;i++)fangan[i]=0,vis[i]=0,dis[i]=LLONG_MAX;
        queue<int> q;
        q.push(start);
        dis[start]=0;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            if(vis[u]||u==n){vis[u]=1;continue;}
            vis[u]=1;
            for(int v=u+1;x[v]-x[u]<=d&&v<=n;v++){
                if(dis[v]>dis[u]+1){
                    dis[v]=dis[u]+1;
                    fangan[v]=1;
                    q.push(v);
                }
                else if(dis[v]==dis[u]+1){
                    fangan[v]++;
                    q.push(v);
                }
            }
        }
        for(int end=start+1;end<=n;end++){
            if(fangan[end]==2){
                ans++;
            }
        }
    }
    cout<<ans<<'\n';
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    c=read(),t=read();
    while(t--){
        solve();
    }
    return 0;
}
