#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=505,M=5e5+5;
const ll inf=1e18;
int c,n,m,d,q;
ll w[M];
struct node{
    int id;
    ll t;
};
vector<node>line[M];
ll dis[N][N];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;++i)cin>>w[i];
    for(int i=1;i<=n;++i){
        int k;
        cin>>k;
        for(int j=1;j<=k;++j){
            int a;
            ll t;
            cin>>a>>t;
            line[a].push_back((node){i,t});
        }
    }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)dis[i][j]=inf;
    for(int i=1;i<=n;++i)dis[i][i]=0;
    for(int i=1;i<=m;++i){
        for(node j:line[i]){
            for(node k:line[i]){
                dis[j.id][k.id]=min(dis[j.id][k.id],j.t+k.t);
            }
        }
    }
    for(int k=1;k<=n;++k){
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        ll res=inf;
        for(node i:line[x]){
            for(node j:line[y]){
                res=min(res,dis[i.id][j.id]+i.t+j.t);
            }
        }
        res+=w[x]+w[y];
        cout<<res<<"\n";
    }
    return 0;
}