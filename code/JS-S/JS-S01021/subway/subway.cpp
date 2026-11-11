#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=1e18;
const int maxn=5e5+5;
ll c,n,m,d,q;
vector<pair<int,ll>> g[maxn+1000]={};
ll born[maxn]={};

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;++i) cin>>born[i];
    for(int i=m+1;i<=n+m;++i){
        int x;
        cin>>x;
        for(int j=0;j<x;++j){
            int y,z;
            cin>>y>>z;
            g[i].push_back({y,z});
            g[y].push_back({i,z});
        }
    }

  // vector<vector<ll>> mn(n+3,vector<ll>(n+3,inf));
    ll mn[503][503];
    for(int i=0;i<=501;++i){
        for(int j=0;j<=501;++j) mn[i][j]=inf;   
    }

    for(int i=1;i<=m;++i){
        for(int j=0;j<(int)g[i].size();++j){
            for(int k=j+1;k<(int)g[i].size();++k){
                if(g[i][j].second+g[i][k].second<mn[g[i][j].first-m][g[i][k].first-m]){
                    mn[g[i][j].first-m][g[i][k].first-m]=g[i][j].second+g[i][k].second;
                    mn[g[i][k].first-m][g[i][j].first-m]=g[i][j].second+g[i][k].second;
                }
            }
        }
    }

  //  cout<<mn[1][2]<<" <-"<<endl;

    for(int i=1;i<=n;++i) mn[i][i]=0;


    for(int k=1;k<=n;++k){
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                if(mn[i][k]+mn[k][j]<mn[i][j]){
                    mn[i][j]=mn[i][k]+mn[k][j];
                }
            }
        }
    }

  //  cout<<mn[1][2]<<" <-"<<endl;

    while(q--){
        int x,y;
        cin>>x>>y;
        ll ans=inf;
        for(int i=0;i<(int)g[x].size();++i){
            for(int j=0;j<(int)g[y].size();++j){
                ans=min(ans,mn[g[x][i].first-m][g[y][j].first-m]+g[x][i].second+g[y][j].second);
            }
        }
        ans+=born[x];
        ans+=born[y];
        cout<<ans<<endl;
    }

    return 0;
}