#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#define int long long
#define pii pair<int,int>
#define fst first
#define snd second

using namespace std;
const int N=510;
const int M=2e4+10;
int c;
int n;
int m;
int d;
int q;
int w[M];   //mouth<->hall
int k[N];
int a[N][M];        //line i pass j
vector<int>ka[M];   //j in which line
int t[N][M];        //in j hall<->line i

int dis[N][N];
priority_queue<pii,vector<pii>,greater<pii>> pq;
void dfs(int u){
    while(!pq.empty()) pq.pop();
    pq.push({0,u});
    while(!pq.empty()){
        int uu=pq.top().snd;
        int du=pq.top().fst;
        pq.pop();
        if(du >= dis[u][uu]){
            continue;
        }
        dis[u][uu]=du;
        for(int i=1; i<=k[uu]; ++i){
            int v=a[uu][i];
            for(auto l:ka[v]){
                pq.push({du+t[uu][v]+t[l][v],l});
            }
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("subway.in" ,"r",stdin );
    freopen("subway.out","w",stdout);
    memset(dis,0x3f3f,sizeof dis);
    cin>>c>>n>>m>>d>>q;
    for(int i=1; i<=m; ++i){
        cin>>w[i];
    }
    for(int i=1; i<=n; ++i){
        cin>>k[i];
        for(int j=1; j<=k[i]; ++j){
            cin>>a[i][j];
            cin>>t[i][a[i][j]];
            ka[a[i][j]].push_back(i);
        }
    }
    for(int i=1; i<=n; ++i){
        dfs(i);
    }
    for(int i=1; i<=q; ++i){
        int ss,tt,ans=dis[0][0];
        cin>>ss>>tt;
        for(auto u:ka[ss]){
            for(auto v:ka[tt]){
                ans=min(ans,dis[u][v]+t[u][ss]+t[v][tt]);
            }
        }
        cout<<w[ss]+w[tt]+ans<<'\n';
    }
    return 0;
}
