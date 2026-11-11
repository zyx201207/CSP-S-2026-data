#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll c,m,n,d,e,w[N];
map<ll,ll>q[N];
vector<pair<ll,ll> >a[N];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>e;
    for(ll i=1;i<=m;i++){
        cin>>w[i];
        for(ll j=1;j<=m;j++){
            q[i][j]=1e14;
            q[j][i]=1e14;
        }
    }
    for(int i=1;i<=n;i++){
        ll o;
        cin>>o;
        for(ll j=1;j<=o;j++){
            ll x,y;
            cin>>x>>y;
            for(auto it:a[i]){
                if(q[it.first][x]!=0){
                    q[it.first][x]=min(it.second+y,q[it.first][x]);
                    q[x][it.first]=min(it.second+y,q[x][it.first]);
                }
                else{
                    q[it.first][x]=it.second+y;
                    q[x][it.first]=it.second+y;
                }
            }
            a[i].push_back({x,y});
        }
    }
    for(ll k=1;k<=m;k++){
        for(ll i=1;i<=m;i++){
            for(ll j=i+1;j<=m;j++){
                q[i][j]=min(q[i][k]+q[k][j],q[i][j]);
                q[j][i]=min(q[i][k]+q[k][j],q[j][i]);
            }
        }
    }
    for(ll i=1;i<=e;i++){
        ll u,v;
        cin>>u>>v;
        cout<<q[u][v]+w[u]+w[v]<<endl;
    }
    return 0;
}
