#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
vector<int> g[N];
int low[N],dfn[N],idx,ne[N*10],e[N*10],head[N],n,k,cnt;
bool bridge[N];
void add(int a,int b){
    e[a]=b;
    ne[cnt]=head[a];
    head[a]=++cnt;
}
void tarjan(int u){
    low[u]=dfn[u]=++idx;
    for(int i=head[u];~i;i=ne[i]){
        int v=ne[i];
        if(low[v]>low[u]){
            tarjan(v);
            low[v]=min(low[u],low[v]);
            bridge[i]=bridge[i^1]=true;
            dfn[v]=min(low[v],dfn[u]);
        }
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<n;i++){
             int u,v;
            cin>>u>>v;
            add(u,v),add(v,u);
        }
       for(int i=1;i<=n;i++)tarjan(i);
       for(int i=1;i<=idx;i++){
            if(bridge[i]){
                cout<<(i^1-i)<<endl;
                break;
            }
       }
    }
    return 0;
}
