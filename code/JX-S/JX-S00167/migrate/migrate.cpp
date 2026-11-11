#include<bits/stdc++.h>
#define CSP2026 using
#define RP namespace
#define PLUSPLUS std
CSP2026 RP PLUSPLUS;
using ll=long long;
#define debug(x) cout<<"clock="<<clock()<<' '<<#x<<'='<<(x)<<'\n'
inline int rd(){int x=0,f=1;char ch=getchar();for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;for(;isdigit(ch);ch=getchar())x=(x<<3)+(x<<1)+(ch^48);return x*f;}
inline ll rdll(){ll x=0;int f=1;char ch=getchar();for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;for(;isdigit(ch);ch=getchar())x=(x<<3)+(x<<1)+(ch^48);return x*f;}
constexpr int N=5005;
struct edge{int to,nxt;}e[N*N];
int h[N],ecnt,dis[N][N],cnt[N][N];
ll a[N];
bitset<N>vis;
void addedge(int u,int v){
    // cout<<u<<'-'<<v<<'\n';
    e[++ecnt]={v,h[u]};
    h[u]=ecnt;
}void solve(int num){
    int n=rd(),ans=0;
    fill(h+1,h+n+1,0);ecnt=0;
    ll d=rdll();
    for(int i=1;i<=n;++i){
        a[i]=rdll();
        for(int j=1;j<i;++j)if(a[i]-a[j]<=d)addedge(i,j),addedge(j,i);
        // if(i>=2)addedge(i,i-1),addedge(i-1,i);
    }for(int i=1;i<=n;++i){
        queue<int>q;
        q.push(i);//vis.reset();
        fill(dis[i]+1,dis[i]+n+1,1e9);
        fill(cnt[i]+1,cnt[i]+n+1,0);
        dis[i][i]=0,cnt[i][i]=1;
        while(!q.empty()){
            int u=q.front();q.pop();
            for(int j=h[u];j;j=e[j].nxt){
                int v=e[j].to;
                if(dis[i][v]==1e9){
                    dis[i][v]=dis[i][u]+1;
                    cnt[i][v]=cnt[i][u];
                    q.push(v);
                }else if(dis[i][v]==dis[i][u]+1)cnt[i][v]+=cnt[i][u];
            }
        }
        for(int j=i;j<=n;++j){
            if(cnt[i][j]==2){
                // cout<<i<<'-'<<j<<' '<<dis[i][j]<<' '<<cnt[i][j]<<'\n';
                // if(dis[i][j]!=2)cerr<<"fail!\n"<<num<<'\n',exit(1);
                ++ans;
            }
        }
    }cout<<ans<<'\n';
}signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    rd();int T=rd();
    for(int i=1;i<=T;++i)solve(i);
}