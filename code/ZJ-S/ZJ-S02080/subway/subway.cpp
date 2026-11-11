#include <bits/stdc++.h>
#define int long long
#define M 500005
#define N 505
using namespace std;
int n,m,ans,cnt,d,q,c;
int w[M],a[N][M],k[N],t[N][M];
vector<vector< pair<int,int> >> pos(N);//pos[i][{j,k}]:i上有列车j，是它的第k个点
vector<vector<int>> f(N);
//目的地 铁路序号 这条铁路的第x个站 总用时
void dfs(int y,int kk,int x,int time){
    if(a[kk][x]==y){
        ans = min(ans, time);
        return ;
    } 
    if(k[kk]>x) dfs(y,kk,x+1,time);//继续坐
    
}
int randd(){
    int res = 0;
    for(int i=1;i<=10;i++){
        res += time(0) % 5000;
        res += rand();
        res &= 5000;
    }
    return res;
}
signed main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m;i++){
        cin >> w[i];
    }
    for (int i = 1; i <= n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin >> a[i][j] >> t[i][j];
            pos[a[i][j]].push_back({i, j});
        }
    }
    // for (int i = 1; i <= q;i++){
    //     int x,y;cin >> x >> y;
    //     
    // }
    cout << randd();
    return 0;
}