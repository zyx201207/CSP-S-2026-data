#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll

const int N=503;
const int M=5e5+3;

int c,n,m,d,q;
int w[M];

vector<pair<int,int>> v[M];

int dis[N][N];

signed main(){
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
        for(int j=1;j<=k;j++){
            int a,t;
            cin>>a>>t;
            v[a].push_back({i,t});
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dis[i][j]=LLONG_MAX>>2;
        }
        dis[i][i]=0;
    }
    for(int i=1;i<=m;i++){
        int k=v[i].size();
        for(int p=0;p<k;p++){
            for(int q=p+1;q<k;q++){
                dis[v[i][p].first][v[i][q].first]
                =dis[v[i][q].first][v[i][p].first]
                =v[i][p].second+v[i][q].second;
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        int ans=LLONG_MAX;
        for(auto i:v[x]){
            for(auto j:v[y]){
                ans=min(ans,w[x]+i.second+dis[i.first][j.first]+j.second+w[y]);
            }
        }
        cout<<ans<<'\n';
    }
    cout<<flush;
    return 0;
}