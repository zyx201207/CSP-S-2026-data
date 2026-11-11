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
ll x[2000005],d,dtf;
bool vis[10];
int cnt;
int n;
void dfs(int u,int v,int dis){
    if(u==v){
        if(dtf==dis)cnt++;
        else if(dtf>dis)cnt=1,dtf=dis;
    }
    vis[u]=1;
    for(int to=1;to<=n;to++){
        if(abs(x[u]-x[to])<=d&&!vis[to]){
            dfs(to,v,dis+1);
        }
    }
    vis[u]=0;
}
void solve1(){
    if(n==1){
        ll tm;
        scanf("%lld",&tm);
        puts("0");
        return;
    }
    ll ans=0;
    for(int i=1;i<=n;i++)scanf("%lld",&x[i]);
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            dtf=inf;
            cnt=0;
            dfs(i,j,0);
            if(cnt==2)ans++;
        }
    }
    printf("%lld\n",ans);
}
void solve2(){
    if(n==1){
        ll tm;
        scanf("%lld",&tm);
        puts("0");
        return;
    }
    for(int i=1;i<=n;i++)scanf("%lld",x+i);
    ll dlt=x[2]-x[1];
    dlt=d/dlt;
    n--;
    if(dlt>1)printf("%lld\n",max(0ll,n-2*dlt+2));
    else puts("0");
}
void solve0(){
    puts("0");
}
void solve(int c){
    scanf("%d%lld",&n,&d);
    if(c>=1&&c<=2)solve1();
    else if(c>=11&&c<=12)solve2();
    else solve0();
}
int main(){
    fileIO("migrate");
    int c,T;
    scanf("%d%d",&c,&T);
    while(T--)solve(c);
}
