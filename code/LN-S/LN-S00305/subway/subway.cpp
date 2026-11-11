#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const int N = 600000;
const int M = 600;

ll dist[M][M];
ll w[N];
int son[N][30];
int sonc[N];
ll sont[N][30];
vector<pair<int,ll>> edge[M];//xianlu

int n,m,d,q,c,k,a,x,y;
ll t;

int main(){

    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin>>c>>n>>m>>d>>q;
    for(int i = 1;i<=m;i++){
        cin>>w[i];
    }
    for(int i = 1;i<=n;i++){
        cin>>k;
        for(int j = 1;j<=k;j++){
            cin>>a>>t;
            son[a][++sonc[a]] = i;
            sont[a][sonc[a]] = t;
            edge[i].push_back({a,t});
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            dist[i][j] = INF;
            if(i == j)dist[i][j] = 0;
        }
    }
    for(int i = 1;i<=n;i++){
        for(auto e : edge[i]){
            int j = e.first;
            ll w1 = e.second;
            for(int k = 1;k<=sonc[j];k++){
                int v = son[j][k];
                ll w2 = sont[j][k];
                if(v == i)continue;
                dist[i][v] = min(dist[i][v],w1 + w2);
                dist[v][i] = dist[i][v];
            }
        }
    }
    //floyd
    for(int d = 1;d<=n;d++){
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                dist[i][j] = min(dist[i][j],dist[i][d] + dist[d][j]);
            }
        }
    }
    while(q--){
        cin>>x>>y;
        ll ans = INF;
        for(int i = 1;i<=sonc[x];i++){
            for(int j = 1;j<=sonc[y];j++){
				//cout<<son[x][i]<<"to"<<son[y][j]<<" "<<sont[x][i] + sont[y][j] + dist[son[x][i]][son[y][j]]<<endl;
                ans = min(ans,sont[x][i] + sont[y][j] + dist[son[x][i]][son[y][j]]);
            }
        }
        //cout<<ans<<endl;
        cout<<ans + w[x] + w[y]<<"\n";
    }
}   
//by qiluo_tsukiro
//guanzhu qiluo xiexie miao qwq
//xiang shang mi huo xing wei da shang awa