#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 500;
const int M = 5e5;

int c,n,m,d,q;
int w[M + 5],k[N + 5];
int dis[N + 5][N + 5],st[N + 5][N + 5],en[N + 5][N + 5];
map<pair<int,int>,int>mp;
int num[M][25],cnt[M];
map<int,int>vis;
int ans;



signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin >> c >> n >> m >> d >> q;
    memset(dis,0x3f,sizeof dis);
    for(int i = 1;i <= n;i++)
        dis[i][i] = 0;
    for(int i = 1;i <= m;i++)
        cin >> w[i];
    int ai,ti;
    for(int i = 1;i <= n;i++){
        cin >> k[i];
        for(int j = 1;j <= k[i];j++){
            cin >> ai >> ti;
            mp[{ai,i}] = ti;
            num[ai][++cnt[ai]]= i;
        }
    }
    for(int i = 1;i <= m;i++){
        if(cnt[i] <= 1)
            continue;
        vis[i] = 1;
        for(int j = 1;j <= cnt[i];j++){
            for(int k = j + 1;k <= cnt[i];k++){
                int x = num[i][j];
                int y = num[i][k];
                dis[y][x] = dis[x][y] = mp[{i,x}] + mp[{i,y}];
                st[x][y] = en[x][y] = i;
                st[y][x] = en[x][y] = i;
            }
        }
    }
    for(int k = 1;k <= n;k++){
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                if(dis[i][j] > dis[i][k] + dis[k][j]){
                    dis[i][j] = dis[i][k] + dis[k][j];
                    st[i][j] = st[i][k];
                    en[i][j] = en[k][j];
                    
                }
            }
        }
    }

    while(q--){
        int x,y;
        cin >> x >> y;
        ans = LONG_LONG_MAX;
        for(int i = 1;i <= cnt[x];i++){
            for(int j = 1;j <= cnt[y];j++){
                int nx = num[x][i],ny = num[y][j];
                if(nx == ny){
                    ans = min(mp[{x,nx}] + mp[{y,ny}],ans);
                    continue;
                }
                int s = dis[nx][ny];
                if(x == st[nx][ny])
                    s -= mp[{x,nx}];
                else
                    s += mp[{x,nx}];
                if(y == st[nx][ny])
                    s -= mp[{y,ny}];
                else
                    s += mp[{y,ny}];
                ans = min(ans,s);
            }
        }
        ans += w[x] + w[y];
        cout << ans << '\n';
    }

}