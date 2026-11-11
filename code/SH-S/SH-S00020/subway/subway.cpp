#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500,M=5e5;
const ll LLINF=0x3f3f3f3f3f3f3f3f;

int c,n,m,d,q,w[M+5];
int k[N+5];
vector<pair<int,int> > edge[M+5];
ll dis[N+5][N+5];

signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) dis[i][j]=0;
            else dis[i][j]=LLINF;
        }
    }
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=0;j<k[i];j++){
            int to,w;
            cin>>to>>w;
            edge[to].push_back({i,w});
        }
    }
    for(int i=1;i<=m;i++){
        for(int u=0;u<edge[i].size();u++){
            for(int v=0;v<u;v++){
                ll t=0;
                t=t+edge[i][u].second;
                t=t+edge[i][v].second;
                dis[edge[i][u].first][edge[i][v].first]=min(dis[edge[i][u].first][edge[i][v].first],t);
                dis[edge[i][v].first][edge[i][u].first]=min(dis[edge[i][v].first][edge[i][u].first],t);
            }
        }
    }
    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            cout<<dis[i][j]<<' ';
        cout<<endl;
    }*/
    for(int _=1;_<=n;_++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dis[i][j]=min(dis[i][j],dis[i][_]+dis[_][j]);
    for(int _q=1;_q<=q;_q++){
        int l,r;
        ll ans=LLINF;
        cin>>l>>r;
        for(int u=0;u<edge[l].size();u++){
            for(int v=0;v<edge[r].size();v++){
                ans=min(ans,dis[edge[l][u].first][edge[r][v].first]+edge[l][u].second+edge[r][v].second);
            }
        }
        cout<<ans+w[l]+w[r]<<'\n';
    }
    return 0;
}
