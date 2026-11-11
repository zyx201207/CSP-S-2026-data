#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int N=500010,INF=1e18;
int c,n,m,d,q;
int w[N],A,B;
vector<pii> vec[N];
int dist[510][510];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin.tie(0),cout.tie(0);ios::sync_with_stdio(false);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j) dist[i][j]=INF;
        }
    }
    for(int i=1;i<=n;i++){
        static int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            static int aa,tt;
            cin>>aa>>tt;
            vec[aa].push_back({i,tt});
        }
    }
    for(int i=1;i<=m;i++){
        for(int x=0;x<vec[i].size();x++){
            for(int y=x+1;y<vec[i].size();y++){
                int stx=vec[i][x].first,sty=vec[i][y].first;
                int tx=vec[i][x].second,ty=vec[i][y].second;
                dist[stx][sty]=dist[sty][stx]=min(dist[stx][sty],tx+ty);
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dist[i][j]=min(dist[i][k]+dist[k][j],dist[i][j]);
            }
        }
    }
    while(q--){
        cin>>A>>B;
        if(A==B){
            cout<<0<<"\n";
            continue;
        }
        int ans=INF;
        for(auto xx:vec[A]){
            for(auto yy:vec[B]){
                ans=min(ans,dist[xx.first][yy.first]+xx.second+yy.second);
            }
        }
        cout<<ans+w[A]+w[B]<<"\n";
    }
    return 0;
}