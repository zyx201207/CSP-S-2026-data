#include<bits/stdc++.h>
#define int long long
#define f(i , l , r) for(int i = (l);i <= (r);i ++)
#define d(i , l , r) for(int i = (r);i >= (l);i --)
#define pii pair<int,int>
#define fi first
#define sc second
#define pb push_back
#define fre(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout)
#define lowbit(x) ((x)&-(x))
using namespace std;
const int N = 2e6 + 10;
int n , k;
struct edge{
    int u , v , nxt;
}e[N<<2];
int head[N] , tot;
void add(int u,int v){
    e[++tot] = {u , v , head[u]};
    head[u] = tot;
}
int f[N] , deep[N] , dis[N];
int now = 0 , hv = 0;
void dfs(int u,int father){
    dis[u] = 0 , deep[u] = deep[father] + 1;
    f[u] = 1;
    for(int i = head[u];i;i = e[i].nxt){
        int v = e[i].v;
        if(v == father)continue ;
        dfs(v , u);
        dis[u] = max(dis[v] + 1 , dis[u]);
        if(dis[v] >= now)f[u] += f[v];
    }
}
bool dfs2(int u,int father){
    int all = 0;
    //cout << u << " " << f[u] << " " <<  k - hv << "\n";
    if(f[u] <= k - hv)return true;
    if(deep[u] - 1 > now)return false;
    for(int i = head[u];i;i = e[i].nxt){
        int v = e[i].v;
        if(v == father)continue ;
        if(dis[v] + deep[u] > now){
            if(all)return false;
            all = v;
        }
    }
    if(!all){
        int ans = 0;
        for(int i = head[u];i;i = e[i].nxt){
            int v = e[i].v;
            if(v == father)continue ;
            ans |= dfs2(v , u);
        }
        return ans;
    }
    else return dfs2(all , u);
}
bool check(int x){
    now = x;
    f(u , 1 , n){
        dfs(u , 0);
        //f(j , 1 , n)cout << f[j] << " ";cout << "\n";
        hv = 1;
        int ans = 0;
        for(int i = head[u];i;i = e[i].nxt){
            int v = e[i].v;
            if(dis[v] >= now)hv += f[v];
        }
        for(int i = head[u];i;i = e[i].nxt){
            int v = e[i].v;
            if(dis[v] >= now)hv -= f[v];
            if(dfs2(v , u))return true;
            if(dis[v] >= now)hv += f[v];
        }
    }
    return false;
}
void work(){
    cin >> n >> k;
    f(i , 1 , n)head[i] = 0;tot = 0;
    f(i , 1 , n - 1){
        int u , v;
        cin >> u >> v;
        add(u , v) , add(v , u);
    }
    int l = 0 , r = n , ans = 0;
    //cout << check(0) << "\n";
    while(l <= r){
        int mid = l + r >> 1;
        if(check(mid))r = mid - 1 , ans = mid;
        else l = mid + 1;
    }
    cout << ans << "\n";
}
signed main(){
	fre("hub");
    int c , T;cin >> c >> T;
    while(T --)work();
}
/*
0 1
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
0 1
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
