#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct P{
    int r, t;
};
const int N=505, M=5e5+5;
const ll inf=1e18;
int num=0;
int wf[M];  // w
vector<P> ind[M];  // station->route
ll dis[N][N];

int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int c, n, m, d, q;
    int kn, a, t;
    P pu, pv;
    int st, en;
    ll ans;
    cin>>c>>n>>m>>d>>q;
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) if(i!=j) dis[i][j]=inf;
    for(int i=1; i<=m; i++){
        cin>>wf[i];
    }
    for(int i=1; i<=n; i++){
        cin>>kn;
        for(int j=1; j<=kn; j++){
            cin>>a>>t;
            ind[a].push_back((P){i,t});
        }
    }
    for(int i=1; i<=m; i++){
        if(ind[i].size()<=1) continue;
        for(int j=0; j<ind[i].size()-1; j++){
            pu=ind[i][j];
            for(int k=j+1; k<ind[i].size(); k++){
                pv=ind[i][k];
                dis[pu.r][pv.r]=pu.t+pv.t;
                dis[pv.r][pu.r]=pu.t+pv.t;
            }
        }
    }
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                dis[i][j]=min(dis[i][j], dis[i][k]+dis[j][k]);
            }
        }
    }
    /*for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
             printf("%d %d: %ld\n", i, j, dis[i][j]);
        }
    }*/
    while(q--){
        cin>>st>>en;
        ans=inf;
        for(int i=0; i<ind[st].size(); i++){
            pu=ind[st][i];
            for(int j=0; j<ind[en].size(); j++){
                pv=ind[en][j];
                ans=min(ans, dis[pu.r][pv.r]+pu.t+pv.t);
            }
        }
        cout<<ans+wf[st]+wf[en]<<endl;
    }
    return 0;
}
