#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 2e5 + 10 , INF = 1e18 , mod = 1e9 + 7 , LOG = 35;
bool flag[MAXN][LOG];
bool ok[MAXN];
int n , m , ans;
int cnt(int x){
    int res = 0;
    for(int i = 1 ; i <= n ; ++i){
        if(ok[i] && flag[i][x]) res++;
    }
    return res;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("and.in" , "r" , stdin);
    freopen("and.out" , "w" , stdout);
    cin>>n>>m;
    for(int i = 1 ; i <= n ; ++i){
        ok[i] = 1;
        int x;
        cin>>x;
        for(int j = 0 ; j < 30 ; ++j){
            if(x & (1LL << j)) flag[i][j] = 1;
        }
    }
    for(int j = 30 ; j >= 0 ; --j){
        if(cnt(j) >= m){
            for(int i = 1 ; i <= n ; ++i){
                if(flag[i][j] == 0) ok[i] = 0;
            }
            ans += (1LL << j);
        }
    }
    cout<<ans;
    return 0;
}
