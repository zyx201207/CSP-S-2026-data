#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define INF 0x3f3f3f3f
#define endl '\n'
#define int ll
using namespace std;
ll read(){
    ll x=0,f=1;
    char ch=getchar();
    while (ch<'0' or ch>'9') {if (ch=='-') f=-f;ch=getchar();}
    while (ch>='0' and ch<='9') x=x*10+(ll)(ch-'0'),ch=getchar();
    return x*f;
}
ll gcd(ll x,ll y){
    if (y==0) return x;
    return gcd(y,x%y);
}
ll qpow(ll x,ll y,ll mod){
    ll ans=1;
    if (mod==-1) mod=1e18;
    while (y){
        if (y&1) ans=(ans*x)%mod;
        x=(x*x)%mod;
        y>>=1;
    }
    return ans;
}
const int N=2e6;
int cc,n,dis[N+5],cnt[N+5];
ll idx[N+5],d;
vector<int> e[N+5];
int dis1[N+5],cnt1[N+5];
void init(){
    for (int i=1;i<=n;i++) e[i].clear();
}
// priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
// void bfs(int st){
//     for (int i=1;i<=n;i++) dis[i]=1e9,cnt[i]=0;
//     while (!q.empty()) q.pop();
//     dis[st]=0,cnt[st]=1;
//     q.push({0,st});
//     while (!q.empty()){
//         int u=q.top().second,val=q.top().first;
//         q.pop();
//         if (val!=dis[u]) continue;
//         for (int v:e[u]){
//             if (v==9 and st==1){
//                 cerr<<u<<" "<<dis[u]<<" "<<cnt[u]<<" "<<dis[v]<<" "<<cnt[v]<<endl<<endl;
//             }
//             if (dis[v]>dis[u]+1){
//                 dis[v]=dis[u]+1,cnt[v]=cnt[u];
//                 q.push({dis[v],v});
//             }
//             else if (dis[v]==dis[u]+1) cnt[v]+=cnt[u];
//         }
//     }
// }
queue<int> q1;
void bfs1(int st){
    for (int i=1;i<=n;i++) dis1[i]=-1,cnt1[i]=0;
    dis1[st]=0,cnt1[st]=1;
    while (!q1.empty()) q1.pop();
    q1.push(st);
    while (!q1.empty()){
        int u=q1.front();
        q1.pop();
        for (int v:e[u]){
            if (dis1[v]==-1){
                dis1[v]=dis1[u]+1,cnt1[v]=cnt1[u];
                q1.push(v);
            }
            else if (dis1[v]==dis1[u]+1) cnt1[v]+=cnt1[u];
        }
    }
}
void solve(){
    // n=read(),d=read();
    cin>>n>>d;
    init();
    // for (int i=1;i<=n;i++) idx[i]=read();
    for (int i=1;i<=n;i++) cin>>idx[i];
    for (int i=1;i<=n;i++){
        for (int j=i+1;j<=n;j++){
            if (idx[j]-idx[i]<=d) e[i].push_back(j),e[j].push_back(i);
            else break;
        }
    }
    ll ans=0;
    for (int i=1;i<=n;i++){
        // bfs(i);
        bfs1(i);
        // bool flot=true;
        // for (int j=1;j<=n;j++) if ((dis[j]!=dis1[j] and dis[j]!=1e19 and dis1[j]!=-1) or cnt1[j]!=cnt[j]){
        //     flot=false;
        //     cerr<<i<<" "<<j<<" "<<dis[j]<<" "<<dis1[j]<<" "<<cnt[j]<<" "<<cnt1[j]<<endl;
        //     break;
        // }
        // if (!flot){
        //     cerr<<"-111111111\n";
        // }
        // printf("\n");
        // if (i==1) for (int j=1;j<=n;j++) printf("%lld : %lld %lld %lld\n",i,j,dis[j],cnt[j]);
        for (int j=i+1;j<=n;j++) if (cnt1[j]==2) ans++;
    }
    printf("%lld\n",ans);
}
signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0),cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cc=read();
    ll t=read();
    while (t--) solve();
    return 0;
}