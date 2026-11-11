#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=4002;
int rt1,rt2;
vector<int> g[N];
void dfs1(int u,int fa,int x){
    int d=0;
    for(auto v:g[u]){
        d+=(v!=x);
        if(v==fa||v==x) continue;
        dfs1(v,u,x);
    }
    if(d<2) rt1=u;
}
int p1[N],p2[N],a[N],mx=-1;
void dfs2(int u,int fa,int x){
    p2[u]=a[u]=1e9;
    for(auto v:g[u]){
        if(v==fa||v==x) continue;
        p1[v]=p1[u]+1,dfs2(v,u,x);
        p2[u]=min(p2[u],p2[v]+1);
    }
    if(p2[u]==1e9) p2[u]=0;
    if(min(p1[u],p2[u])>mx){
        mx=min(p1[u],p2[u]);
        rt2=u;
    }
}
void dfs3(int u,int fa,int x){
    for(auto v:g[u]){
        if(v==fa||v==x) continue;
        dfs3(v,u,x);
        a[u]=min(a[u],a[v]+1);
    }
    if(a[u]==1e9) a[u]=0;
}
int u[N],v[N],cnt[N];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int c,T;
    cin>>c>>T;
    while(T--){
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            g[i].clear();
        }
        for(int i=1;i<n;i++){
            cin>>u[i]>>v[i];
            g[u[i]].push_back(v[i]);
            g[v[i]].push_back(u[i]);
        }
        int ans=n-1;
        for(int i=1;i<n;i++){
            dfs1(u[i],0,v[i]);
            p1[rt1]=rt2=0,mx=-1;
            dfs2(rt1,0,v[i]);
            dfs3(rt2,0,v[i]);
            dfs1(v[i],0,u[i]);
            p1[rt1]=rt2=0,mx=-1;
            for(int j=1;j<=n;j++){
                p2[j]=1e9;
            }
            dfs2(rt1,0,u[i]);
            dfs3(rt2,0,u[i]);
            int tot=n;
            for(int j=1;j<=n;j++){
                cnt[a[j]]++;
            }
            for(int j=0;j<=n-1;j++){
                if(k>=tot){
                    ans=min(ans,j);
                    break;
                }
                tot-=cnt[j];
            }
            for(int j=1;j<=n;j++){
                cnt[a[j]]--;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}