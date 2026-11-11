#include<bits/stdc++.h>
#define int long long
#define f(i , l , r) for(int i = (l);i <= (r);i ++)
#define d(i , l , r) for(int i = (r);i >= (l);i --)
#define pii pair<int,int>
#define fi first
#define sc second
#define fre(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout)
#define lowbit(x) ((x)&-(x))
using namespace std;
const int N = 1e6 + 10;
int n , a[N];
struct edge{
    int u , v , nxt;
}e[N<<2];
int head[N] , tot;
void add(int u,int v){
    e[++tot] = {u , v , head[u]};
    head[u] = tot;
}
int tree[N];
void input(int u,int x){
    for(;u <= limit;u += lowbit(u))tree[u] += x;
}
int query(int u){
    int ans = 0;
    for(;u;u -= lowbit(u))ans += tree[u];
    return ans;
}
int dis[N];
void dj(int s){
    priority_queue<pii , vector<pii> , greater<pii> >q;
    f(i , 1 , n)dis[i] = 1e18 , vis[i] = 0;
    dis[s] = 0;
    q.push({dis[s] , s});
    while(!q.empty()){
        int u = q.top().sc;q.pop();
        if(vis[u])continue ;
        vis[u] = 1;
        for(int i = head[u];i;i = e[i].nxt){
            int v = e[i].v;
            if(dis[v] > dis[u] + e[i].w){
                dis[v] = dis[u] + e[i].w;
                q.push({v , dis[v]});
            }
        }
    }
}
int p[N] , t[N] , sa[N] , rnk[N];
void Sort(int n,int sz){
    f(i , 0 , sz)t[i] = 0;
    f(i , 1 , n)t[rnk[i]] ++;
    f(i , 1 , sz)t[i] += t[i-1];
    f(i , 1 , n)sa[ t[rnk[i]]-- ] = i;
}
void SA(int n){
    f(i , 1 , n)rnk[i] = s[i] - 'a';
    sz = 26;
    for(int len = 1;sz <= len;len <<= 1 , sz = 0){
        rnk[i] = 
    }
}
int dfn[N] , low[N] , dfnCnt , in[N] , st[N] , h;
int scc[N] , sccCnt;
void Tarjan(int u){
    st[++h] = u , in[u] = 1;
    dfn[u] = low[u] = ++dfnCnt;
    for(int i = head[u];i;i = e[i].nxt){
        int v = e[i].v;
        if(!dfn[v]){
            dfn(v);
            low[u] = min(low[u] , low[v]);
        }
        else if(in[v]){
            low[u] = min(low[u] , dfn[v]);
        }
    }
    if(dfn[u] == low[u]){
        sccCnt ++;
        while(1){
            int v = st[h--];
            in[v] = 0;
            scc[v] = sccCnt;
            if(v == u)continue ;
        }
    }
}
void work(){

}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0) , cout.tie(0);
    int T = 1;
    cin >> T;
    while(T --)work();
}
/*
Oct31==Dec25?
*/