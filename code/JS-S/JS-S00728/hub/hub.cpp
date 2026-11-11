#include<bits/stdc++.h>
using namespace std;
const int M=1000006;
namespace N2{
int n,k;
vector<pair<int,int>> g[M];
int col[M];
pair<int,int> e[M];
int ncnt[2];
void dfs(int u,int f,int c){
    col[u]=c;
    ncnt[c]++;
    for(auto v:g[u])if(v.first!=f)dfs(v.first,u,c);
}
int deg[M];
bool del[M];
int sum[M];
int que[M],l,r;
void solve(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)g[i].clear();
    for(int i=1;i<n;i++){
        int u,v;scanf("%d%d",&u,&v);
        e[i]={u,v};
        g[u].push_back({v,i}),g[v].push_back({u,i});
    }
    int ans=n;
    for(int i=1;i<n;i++){
        for(int j=1;j<=n;j++)del[j]=0;
        ncnt[0]=ncnt[1]=0;
        dfs(e[i].first,e[i].second,0);
        dfs(e[i].second,e[i].first,1);
        queue<int> q[2];
        for(int j=1;j<=n;j++){
            deg[j]=g[j].size()-(j==e[i].first||j==e[i].second);
        }
        for(int j=1;j<=n;j++)sum[j]=0;
        auto check=[&](int tp){
            int cnt=0,i;
            for(i=1;i<=n;i++){
                int nr=r;
                while(l<=r){
                    cnt++;
                    int u=que[l++];
                    for(auto ed:g[u])if(col[ed.first]==col[u]&&!del[ed.first]){
                        deg[ed.first]--;
                        if(deg[ed.first]==1)del[ed.first]=1,que[++nr]=ed.first;
                    }
                }
                r=nr;
                sum[i]+=max(1,ncnt[tp]-cnt);
            }
        };
        l=0,r=-1;
        for(int j=1;j<=n;j++)if(deg[j]==1&&col[j]==0)que[++r]=j;
        check(0);
        l=0,r=-1;
        for(int j=1;j<=n;j++)if(deg[j]==1&&col[j]==1)que[++r]=j;
        check(1);
        for(int i=n;i;i--)if(sum[i]<=k)ans=min(ans,i);
    }
    printf("%d\n",ans);
}
}
namespace K2{

int n,k;
vector<int> g[M];
int mx[M],dia[M];
void dfs(int u,int f){
    int mx2=0;
    mx[u]=0;
    for(auto v:g[u])if(v!=f){
        dfs(v,u);
        if(mx[v]>mx[u])mx2=mx[u],mx[u]=mx[v];
        else if(mx[v]>mx2)mx2=mx[v];
    }
    dia[u]=mx2+mx[u]+1;
    mx[u]++;
}
int ans;
void dfs2(int u,int f,int mxu,int du){
    ans=min(ans,max(dia[u]/2,du/2));
    int mx1=0,mx2=0;
    for(auto v:g[u])if(v!=f){
        if(mx[v]>mx1)mx2=mx1,mx1=mx[v];
        else if(mx[v]>mx2)mx2=mx[v];
    }
    for(auto v:g[u])if(v!=f){
        if(mx[v]==mx1){
            dfs2(v,u,max(mxu+1,mx2+1),max(du,mxu+mx2+1));
        }
        else{
            dfs2(v,u,max(mxu+1,mx1+1),max(du,mxu+mx1+1));
        }
    }
}
void solve(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)g[i].clear();
    for(int i=1;i<n;i++){
        int u,v;scanf("%d%d",&u,&v);
        g[u].push_back(v),g[v].push_back(u);
    }
    ans=n;
    dfs(1,0);
    dfs2(1,0,0,0);
    printf("%d\n",ans);
}

}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int t,ct;
    scanf("%d%d",&ct,&t);
    if(ct!=11&&ct!=12)while(t--)N2::solve();
    else
    while(t--)K2::solve();
    return 0;
}