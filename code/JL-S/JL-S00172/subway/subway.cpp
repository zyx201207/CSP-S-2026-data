#include<bits/stdc++.h>
using namespace std;
#define int long long
int C,n,m,d,q;
const int M = 5e5+10;
int w[M];
vector<int>a[505];
map<int,int>t[M];
int dis[505][505];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> C>>n>>m>>d>>q;
    for(int i = 1; i <= m; i++)cin >> w[i];
    for(int i = 1; i <= n; i++){
        int k;
        cin >> k;
        for(int j = 1; j <= k; j++){
            int x,y;
            cin >>x >> y;
            a[i].push_back(x);
            t[x][i]=y;
        }
    }
    memset(dis,0x3f,sizeof dis);
    for(int i = 1; i <= m; i++){
        for(auto x:t[i]){
            for(auto y:t[i]){
                if(x.first>=y.first)continue;
                dis[x.first][y.first]=dis[y.first][x.first]=min(dis[x.first][y.first],x.second+y.second);
            }
        }
    }
    for(int i = 1; i <= n; i++)dis[i][i]=0;
    for(int k = n; k >= 1; k--){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= n; j++){
    //         cerr<<dis[i][j]<<' ';
    //     }
    //     cerr<<'\n';
    // }
    while(q--){
        int x,y;
        cin >> x >> y;
        int ans = 1e18;
        for(auto i:t[x]){
            for(auto j:t[y]){
                ans=min(ans,dis[i.first][j.first]+i.second+j.second);
            }
        }
        cout << ans+w[x]+w[y]<<'\n';
    }
    return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/