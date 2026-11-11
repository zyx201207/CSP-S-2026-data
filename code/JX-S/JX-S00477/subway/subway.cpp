#include<bits/stdc++.h>
using namespace std;
const int N=510;
struct node{
    int to,l;
};
vector<node>g[510];
int ans=INT_MAX,num=0,cnt;
int w[510],t[510][500010],a[510][500010];
bool vis[5100];
void dfs(int x,int y,int now){
    if(x==y){
        ans=min(ans,cnt+t[now][x]);
        return;
    }
    for(int i=0;i<g[x].size();i++){
        int v=g[x][i].to,w=g[x][i].l;
        if(now!=w)cnt+=t[now][x];
        cnt+=t[w][x];
        dfs(v,y,w);
        if(now!=w)cnt-=t[now][x];
        cnt-=t[w][x];
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a[i][j]>>t[i][a[i][j]];
        }
        for(int j=2;j<=k;j++){
            g[a[i][j-1]].push_back({a[i][j],i});
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        for(int i=0;i<g[x].size();i++){
            cnt=0;
            dfs(x,y,g[x][i].l);
        }
        num=w[x]+w[y]+ans;
        cout<<num<<endl;
    }
    return 0;
}
