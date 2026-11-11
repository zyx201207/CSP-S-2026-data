#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
const int N = 2e6+5;
const int mod = 1e9+7;
const int K = 5;
const int inf = 1<<30;
const bool debug = 0;
#define file "hub"
//15 pts
ll n,k;
int head[N];
int to[N],nxt[N];
int ent = 2;

void addEdge(int u,int v){
    to[ent] = v;
    nxt[ent] = head[u];
    head[u] = ent++;
}

ll ok[N];
int siz = 0;

/*
显然这题我见过类似的，没细看题解，悔恨了，死了-_-
那题应该是给定u,v然后把u->v的路径上的点均设为关键点，
求非关键点到关键点距离的第k大 （）
*/

ll re();
void judge();
void sol();
void read();

int main(){
    if(!debug){
        freopen(file".in","r",stdin);
        freopen(file".out","w",stdout);
    }
    ll c = re(),t = re();
    while(t--){
        judge();
    }
    return 0;
}

void reset(){
     ent = 2;
     siz = 0;
    for(int i = 1;i <= n;i++){
        head[i] = 0;
    }
}

void read(){
   
    n = re(),k = re();
    reset();
    for(int i = 1;i < n;i++){
        int u = re(),v = re();
        addEdge(u,v);
        addEdge(v,u);
    }
}

void init(ll p){
    ll maxn = (1<<p);
    for(int s = 0;s < maxn;s++){
        if(__builtin_popcount(s) == k){
            ok[++siz] = s;
        }
    }
    // printf("siz = %d\n",siz);
}

void judge(){
    
   read();
   init(n);
   sol();
}


ll dis[N];
int oknode[N];

void assess(int u,int f){
    for(int e = head[u];e;e=nxt[e]){
        int v = to[e];
        if(v == f)continue;
        if(dis[v] > dis[u] + 1){
            dis[v] = dis[u]+1;
            assess(v,u);
        }
    }
}

bitset<N> vis;

void search(int u,int f,ll s){
    for(int i = head[u];i;i=nxt[i]){
        int v = to[i];
        if(v == f || vis[v])continue;
        if( (s>>(v-1)) & 1  ){
            vis[v] = 1;
            search(v,u,s);
        }
    }
}

void sol(){
    ll ans = LLONG_MAX;
    for(int id = 1;id <= siz;id++){
        
        ll s = ok[id];
        int tm = 0;
        for(int i = 1;i <= n;i++){
            dis[i] = inf;
            if( (s>>(i-1)) & 1 ){
                dis[i] = 0;
                oknode[++tm] = i;
            }
        }
        ll nums = 0;// <= 2
        for(int i = 1;i <= tm;i++){
            assess(oknode[i],0);
            if(!vis[oknode[i]]){
                search(oknode[i],0,s);
                nums++;
            }
        }
        for(int i = 1;i <= tm;i++){
            vis[oknode[i]] = 0;
        }
        if(nums > 2)continue;
        ll maxdis = 0;
        for(int j = 1;j <= n;j++){
            maxdis = max(maxdis,dis[j]);
        }
        // bitset<9> bt(s);
        // cout << bt;
        // printf("state %lld scale %lld maxdis=%lld\n",s,nums,maxdis);
        ans = min(maxdis,ans);
    }
    printf("%lld\n",ans);
}

ll re(){
    ll x = 0,t = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){
        if(ch == '-')t = -t;
        ch = getchar();
    }
    while('0' <= ch && ch <= '9'){
        x = (x << 1) + (x << 3) + ch - 48;
        ch = getchar();
    }
    return x * t;
} 