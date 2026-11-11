#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

void solve(){
    int n,k;
    cin>>n>>k;
    vector<vector<int>> G(n);
    for(int i=1,u,v;i<n;i++){
        cin>>u>>v,u--,v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<int> dfn(n),rdfn(n);
    int cdfn=0;
    vector<int> dep(n),maxd(n),outd(n),fa(n);
    auto dfs1=[&](auto&&dfs,int u)->void {
        dfn[u]=cdfn++;
        for(int v:G[u])if(v!=fa[u]){
            fa[v]=u,dep[v]=dep[u]+1;
            dfs(dfs,v);
            maxd[u]=max(maxd[u],maxd[v]+1);
        }
        rdfn[u]=cdfn;
    };
    dfs1(dfs1,0);
    auto dfs2=[&](auto&&dfs,int u)->void {
        int max1=-1,max2=-1;
        for(int v:G[u])if(v!=fa[u]){
            if(maxd[v]>max1)max2=max1,max1=maxd[v];
            else max2=max(max2,maxd[v]);
        }
        for(int v:G[u])if(v!=fa[u]){
            outd[v]=max(outd[u],maxd[v]==max1?max2:max1)+1;
            dfs(dfs,v);
        }
    };
    outd[0]=-1;
    dfs2(dfs2,0);
    auto qmaxd=[&](int u,int from)->int {
        return fa[u]==from?maxd[u]:outd[from];
    };
    vector<int> f(n),g(n);
    auto check=[&](const int lim)->bool {
        auto dfs1=[&](auto&&dfs,int u)->void {
            f[u]=1;
            for(int v:G[u])if(v!=fa[u])dfs(dfs,u),f[u]+=f[v];
            if(maxd[u]<lim)f[u]=0;
        };
        dfs1(dfs1,0);
        auto dfs2=[&](auto&&dfs,int u)->void {
            int sum=0;
            for(int v:G[u])if(v!=fa[u])sum+=f[v];
            for(int v:G[u])if(v!=fa[u]){
                g[v]=outd[v]<lim?0:g[u]+sum-f[v]+1;
                dfs(dfs,v);
            }
        };
        g[0]=0;
        dfs2(dfs2,0);
        return 1;
    };
    int L=0,R=n;
    while(L<R){
        int mid=(L+R)>>1;
        if(check(mid))R=mid;
        else L=mid+1;
    }
    cout<<L<<endl;
}

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    int _,T;
    cin>>_>>T;
    while(T--)solve();
    return 0;
}