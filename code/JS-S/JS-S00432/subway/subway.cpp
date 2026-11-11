#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int c,n,m,d,q;
int w[N];
struct node{
    int ki,t;
};
node e[N][N];
int u,v;
bool vis[N];
int dis[N][N];
void dfs(int id,int fa){
    for(int i=1;i<=m;i++){
        if(e[id][i].t&&i!=fa){

        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        int a1,t1;
        for(int i=1;i<=k;i++){
            int a,t;
            cin>>a>>t;
            if(i==1){
                a1=a;
                t1=t;
            }else{
                e[a1][a].ki=k;
                e[a][a1].ki=k;
                e[a1][a].t=t;
                e[a][a1].t=t1;
                a1=a;
                t1=t;
            }
        }
    }
    for(int i=1;i<=q;i++){
        cin>>u>>v;
        cout<<e[u][v].t+w[u]+w[v]<<"\n";
    }
    return 0;
}
