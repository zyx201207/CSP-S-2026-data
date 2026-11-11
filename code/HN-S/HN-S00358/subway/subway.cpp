#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5,M=505;
const ll inf=1e16;
int c,n,m,D,q;
ll d[M][M],w[N];
struct node{
    int x;
    ll c;
};
vector<node> ve[N];
void floyd(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>D>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) d[i][j]=(i!=j)*inf;
    }
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        for(int j=1;j<=x;j++){
            int y,c;
            cin>>y>>c;
            ve[y].push_back({i,c});
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<ve[i].size();j++){
            int u=ve[i][j].x;
            for(int k=j+1;k<ve[i].size();k++){
                int v=ve[i][k].x;
                d[v][u]=d[u][v]=min(d[u][v],ve[i][j].c+ve[i][k].c);
            }
        }
    }
    floyd();
    while(q--){
        int u,v;
        cin>>u>>v;
        ll mn=inf;
        for(int i=0;i<ve[u].size();i++){
            int x=ve[u][i].x;
            for(int j=0;j<ve[v].size();j++){
                int y=ve[v][j].x;
                mn=min(mn,ve[u][i].c+ve[v][j].c+d[x][y]);
            }
        }
        cout<<mn+w[u]+w[v]<<'\n';
    }
    return 0;
}