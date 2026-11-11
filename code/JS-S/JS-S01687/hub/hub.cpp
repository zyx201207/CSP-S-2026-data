#include <bits/stdc++.h>
#define ll long long
#define isok cout << "ok" << endl
#define DB(s,a) cout << s << ":" << a << endl
using namespace std ;
const ll MAXN = 5004 ;
ll c , t , n , d , i , j , ans , x[MAXN] , dis[MAXN] , cnt[MAXN] , rd[MAXN][MAXN] ;
bool vis[MAXN] ;
vector<ll> a[MAXN] ;
void bfs(ll x){
    memset(dis,0x3f,sizeof(dis)) ;
    memset(vis,false,sizeof(vis)) ;
    memset(cnt,0,sizeof(cnt)) ;
    queue<ll> q ;
    q.push(x) ;
    dis[x] = 0 ;
    cnt[x] = 1 ;
    while(!q.empty()){
        ll u = q.front() ;
        q.pop() ;
        for(auto &&v : a[u]){
            if(dis[v]>dis[u]+1){
                dis[v] = dis[u]+1 ;
                cnt[v] = cnt[u] ;
                q.push(v) ;
            }else {
                if(dis[v]==dis[u]+1){
                    cnt[v]++ ;
                }
            }
        }
    }
    for(ll i=1;i<=n;i++){
        rd[x][i] = cnt[i] ;
    }
}
int main(){
    freopen("hub.in","r",stdin) ;
    freopen("hub.out","w",stdout) ;
    ios::sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;
//好看一点
//结...束了吗
//可能我早就AFO了
//可还是放不下啊
//OI你个臭杂鱼
    return 0 ;
}
