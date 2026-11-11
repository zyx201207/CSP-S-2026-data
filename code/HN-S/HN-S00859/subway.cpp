#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,M=5e5+5;
int c,n,m,d,q;
int f[505][505],k[N],a[M];
vector<int> line[N];
vector<pair<int,int>> sta[M];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> c >> n >> m >> d >>q;
    memset(f,0x3f,sizeof f);
    for(int i=1;i<=m;i++){
        cin >> a[i];
    }
    for(int i=1;i<=n;i++){
        f[i][i]=0;
        cin >> k[i];
        for(int j=1;j<=k[i];j++){
            int x,y;
            cin >> x >> y;
            line[i].push_back(x);
            sta[x].push_back({i,y});
        }
    }
    for(int i=1;i<=m;i++){
        int siz=sta[i].size();
        for(int j=0;j<siz;j++){
            for(int k=0;k<siz;k++){
                if(j==k)continue;
                f[sta[i][k].first][sta[i][j].first]=f[sta[i][j].first][sta[i][k].first]=min(f[sta[i][j].first][sta[i][k].first],sta[i][j].second+sta[i][k].second);
                // cout << i << ' ' << j << ' ' << k << ' ' << sta[i][k].second+sta[i][j].second << '\n';
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(f[i][k]+f[k][j]<f[i][j]){
                    f[i][j]=f[i][k]+f[k][j];
                }
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cerr<<f[i][j]<<' ';
    //     }
    //     cerr<<'\n';
    // }
    while(q--){
        int l,r;
        cin >> l >> r;
        int ans=1e18;
        for(int i=0;i<sta[l].size();i++){
            for(int j=0;j<sta[r].size();j++){
                ans=min(sta[l][i].second+sta[r][j].second+f[sta[l][i].first][sta[r][j].first],ans);
            }
        }
        cout << ans+a[l]+a[r] << '\n';
    }
    return 0;
}