#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll=long long;
const int N=505,M=500005;
const ll inf=1e18;
int n,m,q,w[M];
bool vis[N];
ll W[N][N];
vector<pair<int,int>>bl[M];

int main(){
#ifndef LOC
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
#endif
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>n>>m>>q>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        while(k--){
            int x,y;
            cin>>x>>y;
            bl[x].emplace_back(i,y);
        }
    }
    memset(W,0x3f,sizeof(W));
    for(int i=1;i<=n;i++)W[i][i]=0;
    for(int i=1;i<=m;i++){
        for(auto[x,tx]:bl[i])
            for(auto[y,ty]:bl[i]){
                if(x==y)continue;
                W[x][y]=min<ll>(W[x][y],tx+ty);
            }
    }
    for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)W[i][j]=min(W[i][j],W[i][k]+W[k][j]);
    while(q--){
        int x,y;cin>>x>>y;
        ll bs=w[x]+w[y],as=inf;
        for(auto[p,tp]:bl[x])for(auto[q,tq]:bl[y]){
            // cerr<<p<<" "<<q<<" "<<tp<<" "<<tq<<endl;
            as=min(as,W[p][q]+tp+tq);
        }
        // cerr<<bs<<" "<<as<<endl;
        cout<<bs+as<<endl;
    }
    return 0;
}