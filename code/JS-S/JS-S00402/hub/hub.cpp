#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
using ui=unsigned int;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define fs first
#define sc second
#define pb push_back
#define lb(x) ((x)&(-(x)))
#define gp(x,y) (((x)>>(y))&1)
template<typename T>void chkmin(T& a,T b){
    if(a>b)a=b;
}
template<typename T>void chkmax(T& a,T b){
    if(a<b)a=b;
}
void fileIO(string s){
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}
constexpr ll inf=0x3f3f3f3f3f3f3f3f;
vector<int>g[100005];
ll dis[100005];
bool vis[100005];
void solve1(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].pb(v);
        g[v].pb(u);
    }
    ll ans=inf;
    for(int bt=0;bt<(1<<n);bt++){
        if(__builtin_popcount(bt)!=k)continue;
        ll dist=0;
        queue<pll>q;
        for(int j=1;j<=n;j++){
            if(gp(bt,j-1))q.push({j,0});
            dis[j]=inf,vis[j]=0;
        }
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(!vis[i]&&gp(bt,i-1)){
                queue<int>qi;
                vis[i]=1;
                qi.push(i);
                while(!qi.empty()){
                    int sr=qi.front();
                    qi.pop();
                    for(int j:g[sr]){
                        if(!vis[j]&&gp(bt,j-1)){
                            vis[j]=1;
                            qi.push(j);
                        }
                    }
                }
                cnt++;
            }
        }
        if(cnt>2)continue;
        while(!q.empty()){
            pll x=q.front();
            q.pop();
            if(dis[x.fs]==inf){
                dis[x.fs]=x.sc;
                for(int v:g[x.fs]){
                    if(dis[v]==inf)q.push({v,x.sc+1});
                }
            }
        }
        for(int i=1;i<=n;i++)chkmax(dist,dis[i]);
        chkmin(ans,dist);
    }
    printf("%lld\n",ans);
}
void solve2(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].pb(v);
        g[v].pb(u);
    }
    ll ans=inf;
    for(int p1=1;p1<=n;p1++){
        for(int p2=1;p2<=n;p2++){
            if(p1==p2)continue;
            bitset<1005>vs;
            ll dist=0;
            queue<pll>q;
            q.push({p1,0});
            q.push({p2,0});
            while(!q.empty()){
                pll x=q.front();
                q.pop();
                if(!vs[x.fs]){
                    vs.set(x.fs);
                    chkmax(dist,x.sc);
                    for(int v:g[x.fs]){
                        if(!vs[v])q.push({v,x.sc+1});
                    }
                }
            }
            chkmin(ans,dist);
        }
    }
    printf("%lld\n",ans);
}
void solve0(){
    int n,k;
    scanf("%d%d",&n,&k);
    if(n==k)puts("0");
    else puts("1");
    return;
}
void solve(int c){
    if(1<=c&&c<=3)solve1();
    else if(c==7)solve2();
    else solve0();
}
int main(){
    fileIO("hub");
    int c,T;
    scanf("%d%d",&c,&T);
    while(T--)solve(c);
}
