#include<bits/stdc++.h>
#define pii pair<int,int> 
#define mk make_pair
#define int long long
using namespace std;
const int N=505,M=5e5+5,INF=1e18+7;
void chkmn(int &x,int y){
    x=min(x,y);    
}
int c,n,m,dd,q;
int w[M],f[N][N];
vector<pii> g[M];
int a[N],d[N];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>dd>>q;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) f[i][j]=INF;
        f[i][i]=0;
    }
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++) {
        int al,x,y;cin>>al;
        for(int j=1;j<=al;j++){
            cin>>x>>y;
            g[x].push_back({i,y});
        }
    }
    for(int i=1;i<=m;i++) {
        for(pii u:g[i]) {
            for(pii v:g[i]) {
                chkmn(f[u.first][v.first],u.second+v.second);
            }
        }
    }
        for(int k=1;k<=n;k++) {
    for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                f[i][j]=min(f[i][k]+f[k][j],f[i][j]);
            }
        }
    }
    int x,y;
    while(q--) {
        cin>>x>>y;
        if(x==y) {
            cout<<0<<'\n';
            continue;
        }
        int ans=INF;
        for(pii u:g[x]) {
            for(pii v:g[y]) {
                ans=min(ans,u.second+v.second+f[u.first][v.first]);
            }
        }
        cout<<ans+w[x]+w[y]<<'\n';
    }
    return 0;
}