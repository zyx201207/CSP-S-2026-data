#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,M=500005,D=20;
int w[M];
vector <pair <int,int> > v[M];//line J crossed station I,with a T cost
int dis[N][N];
signed main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int c,n,m,d,q;
    cin >> c >> n >> m >> d >> q;
    for(int i=1;i<=m;++i) cin >> w[i];
    for(int i=1;i<=n;++i) {
        int k; cin >> k;
        for(int j=1;j<=k;++j) {
            int a,t; cin >> a >> t;
            v[a].push_back(make_pair(i,t));
        }
    }
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=n;++i) dis[i][i]=0;
    for(int i=1;i<=m;++i) {
        for(int j=0;j<v[i].size();++j)
            for(int k=0;k<v[i].size();++k)
                if(j!=k) {
                    //line J1 & line J2
                    int st1=v[i][j].first,st2=v[i][k].first;
                    int tim=v[i][j].second+v[i][k].second;
                    // cout << "edge : " << st1 << " " << st2 << " " << tim << "\n";
                    dis[st1][st2]=min(dis[st1][st2],tim);
                }
    }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            for(int k=1;k<=n;++k)
                dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
    for(int i=1;i<=q;++i) {
        int ans=LLONG_MAX;
        int s,t; cin >> s >> t;
        for(int j=0;j<v[s].size();++j)
            for(int k=0;k<v[t].size();++k)
                ans=min(ans,w[s]+w[t]+v[s][j].second+v[t][k].second+dis[v[s][j].first][v[t][k].first]);
        cout << ans << "\n";
    }
    return 0;
}