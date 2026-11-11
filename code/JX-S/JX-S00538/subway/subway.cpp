#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=5e5+5;
int c,n,m,d,q;
int w[M],li[M],tim[M][21],len[M],vis[M];
ll ans;
struct node{
    int v,lin,t;
};
vector<node>G[M];
void dfs(int x,int y,int lst,ll sum){
    //cout<<x<<' '<<sum<<' ';
    ll idx=-1;
    for(int i=0;i<G[x].size();i++){
        if(G[x][i].lin==lst){
            idx=i;
            break;
        }
    }
    if(x==y){
        ans=min(ans,sum+tim[x][G[x][idx].t]);
        //cout<<'\n';
        return;
    }
    vis[x]=1;
    ll add=0;
    for(int i=0;i<G[x].size();i++){
        add=0;
        int v=G[x][i].v;
        if(vis[v])continue;
        if(lst!=G[x][i].lin){
            if(idx!=-1){
               add+=tim[x][G[x][idx].t];
            }
            add+=tim[x][G[x][i].t];
        }
        dfs(v,y,G[x][i].lin,sum+add);
        vis[x]=0;
    }
    return;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>li[j]>>tim[li[j]][++len[li[j]]];
            if(j!=1){
                G[li[j-1]].push_back({li[j],i,len[li[j-1]]});
                G[li[j]].push_back({li[j-1],i,len[li[j]]});
            }
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        memset(vis,0,(m+1)*sizeof(int));
        ans=LLONG_MAX;
        dfs(x,y,0,w[x]+w[y]);
        cout<<ans<<'\n';
    }
    return 0;
}
