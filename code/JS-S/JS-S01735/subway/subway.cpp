#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll w[500005];
int k[500005];
struct Node{
    int l;
    ll t;//line,time
};
vector<Node>ps[500005];
ll floyd[505][505];
const ll inf=1e12;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            int x,y;
            cin>>x>>y;
            ps[x].push_back({i,y});
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            floyd[i][j]=floyd[j][i]=inf;
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<ps[i].size()-1;j++){
            for(int k=j+1;k<ps[i].size();k++){
                int x=ps[i][j].l,y=ps[i][k].l;
                floyd[y][x]=floyd[x][y]=min(floyd[x][y],ps[i][j].t+ps[i][k].t);
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                floyd[i][j]=min(floyd[i][j],floyd[i][k]+floyd[k][j]);
            }
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        ll ans=inf;
        for(int j=0;j<ps[x].size();j++){
            for(int k=0;k<ps[y].size();k++){
                ans=min(ans,floyd[ps[x][j].l][ps[y][k].l]+w[x]+w[y]+ps[x][j].t+ps[y][k].t);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
