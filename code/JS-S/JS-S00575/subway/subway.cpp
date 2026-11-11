#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
#define ll long long
int c,n,m,d,q;
int a[1010][1010],t[1010][1010];
int w[N];
struct st{
    int v,id;
};
vector<st> g[510];
void dfs(int u,int d,int fa,int res){
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i].v;
        int id=g[u][i].id;
        if(v==fa) continue;
        if(d!=id) res+=t[id][v];
        dfs(v,id,u,res);
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a[i][j]>>t[i][j];
            for(int l=1;l<j;l++){
                g[a[i][l]].push_back({a[i][j],i});
            }
        }
    }
    for(int r=1;r<=q;r++){
        int x,y;
        cin>>x>>y;

    }
    return 0;
}
