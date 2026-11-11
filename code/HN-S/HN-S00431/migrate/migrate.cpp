#include<bits/stdc++.h>
using namespace std;
const long long inf=2e18+10;
int c,T;
int n;
long long d,p[2001000],f[2001000],ans,dis[2001000];
void solve1(){
    ans=0;
    for(int i=1;i<=n;i++){
        f[i]=1;
        dis[i]=0;
        for(int j=i+1;j<=n;j++){
            f[j]=0;
            dis[j]=inf;
            for(int l=j-1;l>=i&&p[j]-p[l]<=d;l--) dis[j]=min(dis[l]+1,dis[j]);
            for(int l=j-1;l>=i&&p[j]-p[l]<=d;l--) if(dis[j]==dis[l]+1) f[j]+=f[l],f[j]=min(3ll,f[j]);
            if(f[j]==2) ans++;
        }
    }    
    printf("%lld\n",ans);
}
void solve(){
    scanf("%d%lld",&n,&d);
    for(int i=1;i<=n;i++){
        scanf("%lld",&p[i]);
        f[i]=0;
    }
    if(c<=10){
        solve1();
    }
    else printf("0\n");
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&T);
    while(T--){
        solve();
    }
    return 0;
}