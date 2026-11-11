#include<bits/stdc++.h>
#define int long long
#define L(i,j,k) for(int i=(j);i<=(k);i++)
#define R(i,j,k) for(int i=(j);i>=(k);i--)
#define vi vector<int>
#define ek emplace_back
using namespace std;
const int M = 2e6+5;
int n,_,T,k,x,y;
int a[M],b[M];
int dis[M],fa[M];
int vis[M],dep[M];
int t,s,d;
int cnt;
vi e[M];
void dfs(int x,int fx,int u,int v){
    dis[x] = dis[fx]+1;fa[x] = fx;
    if(dis[x]>d)s = x,d = dis[x];
    for(int y:e[x]){
        if(y==fx||(x==u&&y==v)||(x==v&&y==u))continue;
        dfs(y,x,u,v);
    }
}
int calc(int x,int u,int v){
    // dis[x] = 0;
    s = x,d = 0;
    dfs(x,0,u,v);
    t = s,d = 0;
    dfs(t,0,u,v);
    d /= 2;
    while(d){
        s = fa[s];
        d--;
    }
    return s;
}
void dfs1(int x,int fx,int u,int v,int lim){
    dep[x] = 0;//vis[x] = 0;
    for(int y:e[x]){
        if(y==fx||(u==x&&v==y)||(u==y&&v==x))continue;
        dfs1(y,x,u,v,lim);
        // vis[x] |= vis[y];
        dep[x] = max(dep[x],dep[y]+1);
    }
    cnt += (dep[x] >= lim);//vis[x] = 1,
    // cnt += vis[x];
}
inline int check(int rt,int u,int v,int lim){
    cnt = 0;
    dfs1(rt,0,u,v,lim);
    return cnt;
}
inline bool work(int u,int v,int lim){
    int rt1 = calc(u,u,v),rt2 = calc(v,u,v);
    // L(i,1,n)vis[i] = 0,dep[i] = 0;
    return check(rt1,u,v,lim)+check(rt2,u,v,lim)<=k;    
}
void sol(){
    cin>>n>>k;
    L(i,1,n)e[i].clear();
    L(i,1,n-1){
        cin>>x>>y;
        a[i] = x,b[i] = y;
        e[x].ek(y),e[y].ek(x);
    }
    int l = 0,r = n-1,ans = n-1;
    while(l<=r){
        int mid = (l+r)>>1,fl = 0;
        R(i,n-1,1){
            if(work(a[i],b[i],mid)){
                r = mid-1,ans = mid;
                fl = 1;
                break;
            }
        }
        if(!fl) l = mid+1;
    }
    cout<<ans<<"\n";
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>_>>T;
    while(T--)sol();
    return 0;
}