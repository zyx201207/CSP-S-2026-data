#include<bits/stdc++.h>
using namespace std;
#define int long long
int Z,n,m,d,q;
int a[500005],k[505];
int dist[3005][3005],go[3005][505];
vector<pair<int,int> >g[505],pt[3005];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>Z>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1,w,t;j<=k[i];j++){
            cin>>w>>t;
            g[i].push_back({t,w});
            pt[w].push_back({t,i});
        }
    }
    if(m<=3000){
        for(int i=1;i<=n;i++){
            for(int j=0;j<g[i].size();j++){
                for(int o=0;o<j;o++){
                    dist[g[i][o].second][g[i][j].second]=
                    dist[g[i][j].second][g[i][o].second]=g[i][j].first+g[i][o].first;
                }
            }
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        cout<<a[x]+a[y]+dist[x][y]<<"\n";
    }
    return 0;
}

