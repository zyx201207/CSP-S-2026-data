#include <cstdio>
using namespace std;
#define ll long long
#define MAXN 1e14
ll c,t,n,d,x[2000003],ans=0,dis[200003],way[200003];
ll ef(ll l,ll r,ll need){
    ll ans=l;
    while (l<r){
        ll mid=(l+r)/2;
        if (x[mid]>need) r=mid;
        else ans=mid,l=mid+1;
    }
    return ans;
}
void solve(ll now,ll deep,ll last){
    if (dis[now]<deep) return;
    if (dis[now]>deep) way[now]=0,dis[now]=deep;
    way[now]+=way[last];
    if (way[now]>2) return;
    for (int i=ef(now,n+1,x[now]+d);i>now;i--){
        solve(i,deep+1,now);
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld %lld",&c,&t);
    while (t--){
        ans=0;
        scanf("%lld %lld",&n,&d);
        for (int i=1;i<=n;i++){
            scanf("%lld",&x[i]);
        }
        for (ll i=1;i<=n;i++) dis[i]=MAXN,way[i]=0;
        for (ll i=1;i<n;i++){
            way[i]=1;dis[i]=0;
            solve(i,0,0);
            for (ll j=i;j<=n;j++){
                if (way[j]==2) ans++;
                //printf("%lld ",way[j]);
                dis[j]=MAXN,way[j]=0;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
