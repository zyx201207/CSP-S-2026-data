#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5,M=505;
int c,n,m,d,q,k,x,y,t;
int w[N],f[M][M],ans;
vector<pair<int,int>>vec[N];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    memset(f,0x3f,sizeof(f));
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        f[i][i]=0;
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>x>>t;
            vec[x].push_back({i,t});
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<vec[i].size();j++){
            for(int k=j+1;k<vec[i].size();k++){
                int u=vec[i][j].first,v=vec[i][k].first;
                f[u][v]=f[v][u]=min(f[u][v],vec[i][j].second+vec[i][k].second);
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    for(int i=1;i<=q;i++){
        cin>>x>>y;ans=LONG_LONG_MAX;
        for(int j=0;j<vec[x].size();j++){
            for(int k=0;k<vec[y].size();k++){
                ans=min(ans,f[vec[x][j].first][vec[y][k].first]+vec[x][j].second+vec[y][k].second+w[x]+w[y]);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
