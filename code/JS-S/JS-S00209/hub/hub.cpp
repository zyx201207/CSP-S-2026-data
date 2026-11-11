#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+2;
int c,t,n,k,tc,sc,ans;
int dfn[maxn],low[maxn],scc[maxn];
bool iis[maxn];
stack<int> stk;
vector<int> g[maxn];
struct node{
    int id,f;
}cnt[maxn];
bool cmp(node x,node y){
    return x.f>y.f;
}
void init(){
    for(int i=1;i<=n;i++) g[i].clear();
    for(int i=1;i<=sc;i++) cnt[i].id=cnt[i].f=0;
    n=k=tc=sc=ans=0;
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    memset(scc,0,sizeof(scc));
    while(!stk.empty()) stk.pop();
}
void tarjan(int u,int fa){
    dfn[u]=low[u]=++tc;
    stk.push(u); iis[u]=true;
    for(int v:g[u]){
        if(!dfn[v]){
            tarjan(v,u);
            low[u]=min(low[u],low[v]);
        }else if(iis[v]) low[u]=min(low[u],dfn[v]);
    }
    if(low[u]==dfn[u]){
        sc++;
        cnt[sc].id=sc;
        while(1){
            int x=stk.top();
            stk.pop();
            iis[x]=false;
            scc[x]=sc;
            cnt[sc].f++;
            if(x==u) break;
        }
    }
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    // tarjanSCC+lying marks
    cin>>c>>t;
    while(t--){
        init();
        cin>>n>>k;
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        tarjan(1,0);
        int mx=0;
        sort(cnt+1,cnt+sc+1,cmp);
        if(cnt[1].f>=k){
            cout<<"0\n";
            continue;
        }
        cout<<"1\n";
    }
    return 0;
}
