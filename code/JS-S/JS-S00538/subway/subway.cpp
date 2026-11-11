#include<bits/stdc++.h>
#define pii pair < int , int >
#define ll long long
using namespace std;
const int N=5e5+5,M=505;
ll w[N];
ll a[M][M];
vector < pair < int , ll > > vec[N];
inline void add(int x,int y,ll z){
    a[x][y]=min(a[x][y],z);
    a[y][x]=min(a[y][x],z);
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    memset(a,0x3f,sizeof(a));
    int c,n,m,d,q;cin>>c>>n>>m>>d>>q;
    for (int i=1;i<=n;i++) a[i][i]=0;
    for (int i=1;i<=m;i++) cin>>w[i];
    for (int i=1;i<=n;i++){
        int k;cin>>k;
        for (int j=1;j<=k;j++){
            int x,t;cin>>x>>t;
            vec[x].push_back({i,t});
        }
    }
    for(int x=1;x<=m;x++){
        for (int i=0;i<vec[x].size();i++){
            for (int j=i+1;j<vec[x].size();j++){
                add(vec[x][i].first,vec[x][j].first,vec[x][i].second+vec[x][j].second);
            }
        }
    }
    for (int k=1;k<=n;k++){
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
            }
        }
    }
    while (q--){
        int x,y;cin>>x>>y;
        ll ans=0x3f3f3f3f3f3f3f3f;
        for (int i=0;i<vec[x].size();i++){
            for (int j=0;j<vec[y].size();j++){
                ans=min(ans,a[vec[x][i].first][vec[y][j].first]+vec[x][i].second+vec[y][j].second);
            }
        }
        cout<<ans+w[x]+w[y]<<'\n';
    }
    return  0;
}

//15:20 100pts