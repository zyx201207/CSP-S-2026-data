#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int c;
int n;
LL cnt[2000005],d,x[2000005];
int dis[2000005];
bitset<2000005> vis;
struct nd{
    int u,dis;
};
void justmodit(int s){
    for (int i=1;i<=n;++i){cnt[i]=1;vis[i]=0;dis[i]=0x3f3f3f3f;}
    dis[s]=0LL;vis[s]=1;cnt[s]=1;
    queue<nd> apple;
    apple.push({s,0});
    nd cur;
    int tl,tr;
    while (!apple.empty()){
        cur=apple.front();apple.pop();
        tr=upper_bound(x+1,x+1+n,x[cur.u]+d)-x-1;
        tl=lower_bound(x+1,x+1+n,x[cur.u]-d)-x;
        for (int t=tl;t<=tr;++t){
            if (!vis[t]){dis[t]=cur.dis+1;vis[t]=1;cnt[t]=cnt[cur.u];apple.push({t,dis[t]});}else if (dis[t]==cur.dis+1){cnt[t]+=cnt[cur.u];}
        }
    }
    return;
}
void solve(){
    scanf("%d%lld",&n,&d);LL ans=0LL;
    for (int i=1;i<=n;++i){scanf("%lld",x+i);}
    for (int i=1;i<n;++i){
        justmodit(i);
        for (int j=i+1;j<=n;++j){
//if (cnt[j]==2){cerr<<i<<" "<<j<<" "<<dis[j]<<" "<<cnt[j]<<endl;}
if (cnt[j]==2){++ans;}}
    }
    printf("%lld\n",ans);
    return;
}
void solve_B(){
    scanf("%d%lld",&n,&d);LL ans=0LL;
    for (int i=1;i<=n;++i){scanf("%lld",x+i);}
    int tl,tr,tl2,tr2;
    for (int i=1;i<=n;++i){
        tr=upper_bound(x+1,x+1+n,x[i]+d)-x-1;
        tl=lower_bound(x+1,x+1+n,x[i]-d)-x;
        tr2=upper_bound(x+1,x+1+n,x[i]+d+d)-x-1;
        tl2=lower_bound(x+1,x+1+n,x[i]-d-d)-x;
        ans+=(tr2-tr)+(tl2-tl);
    }
    printf("%lld\n",ans);
    return;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int T;scanf("%d%d",&c,&T);
    if (c>=13&&c<=14){++T;while (--T){solve_B();}return 0;}
    ++T;while (--T){solve();}
    return 0;
}
