#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 5e2 + 10 , INF = 1e18 , mod = 1e9 + 7 , MAXM = 5e5 + 10 , MAXD = 20 + 5;
int c , n , m , d , q , ans;
int w[MAXM] , k[MAXN];
struct node{
    int to , val;
};
vector<int> a[MAXN];
vector<int> t[MAXN];
vector<node> g[MAXN];
int dp[MAXM][2];
int s , e;
void dfs(int x , int id , int sum){
    if(sum >= ans) return ;
    if(dp[x][id] < sum) return ;
    dp[x][id] = sum;
    if(x == e && id == 0){
        ans = sum;
        return ;
    }
    if(id == 0) dfs(x , 1 , sum + w[x]);
    if(id == 1){
        dfs(x , 0 , sum + w[x]);
        for(auto u : g[x]){
            int v = u.to , w = u.val;
            dfs(v , 1 , sum + w);
        }
    }
}
void solve(){
    cin>>s>>e;
    ans = INF;
    for(int i = 1 ; i <= m ; ++i){
        dp[i][0] = dp[i][1] = INF;
    }
    dfs(s , 0 , 0);
    cout<<ans<<"\n";
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("subway.in" , "r" , stdin);
    freopen("subway.out" , "w" , stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i = 1 ; i <= m ; ++i){
        cin>>w[i];
    }
    for(int i = 1 ; i <= n ; ++i){
        cin>>k[i];
        for(int j = 1 ; j <= k[i] ; ++j){
            int x , y;
            cin>>x>>y;
            a[i].push_back(x);
            t[i].push_back(y);
        }
        for(int j = 0 ; j < k[i] ; ++j){
            for(int l = j + 1 ; l < k[i] ; ++l){
                int u = a[i][j] , v = a[i][l] , w = t[i][j] + t[i][l];
                g[u].push_back({v , w});
                g[v].push_back({u , w});
            }
        }
    }
    while(q--){
        solve();
    }
    return 0;
}
