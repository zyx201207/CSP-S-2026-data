#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
const ll M=1e18;

ll c,n,m,d,q,u,v,x,y,vx,vy;
ll w[500005],t[500005][22],td[500005][22],ct[500005];
ll k[505],a;
ll dis[505][505];
ll mp[505][505];

void solve(){
    ll ans=M;
    scanf("%lld %lld",&u,&v);
    ll lu=ct[u],lv=ct[v];
    for(int i=1;i<=lu;i++){
        for(int j=1;j<=lv;j++){
            x=td[u][i];vx=t[u][i];
            y=td[v][j];vy=t[v][j];
            ans=min(ans,dis[x][y]+vx+vy);
        }
    }
    printf("%lld\n",ans+w[u]+w[v]);
    return;
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++){
        scanf("%lld ",&w[i]);
        ct[i]=0;
    }
    for(int i=1;i<=n;i++){
        scanf("%lld",&k[i]);
        for(int j=1;j<=k[i];j++){
            scanf("%lld ",&a);
            ct[a]++;
            scanf("%lld ",&t[a][ct[a]]);
            td[a][ct[a]]=i;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j) mp[i][j]=dis[i][j]=M;
            else mp[i][j]=dis[i][j]=0;
        }
    }
    for(int i=1;i<=m;i++){
        for(int j1=1;j1<=ct[i];j1++){
            for(int j2=1;j2<=ct[i];j2++){
                if(j1==j2) continue;
                u=td[i][j1];x=t[i][j1];
                v=td[i][j2];y=t[i][j2];
                mp[u][v]=min(x+y,mp[u][v]);
                dis[u][v]=mp[u][v];
            }
        }
    }
    //floyd
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }

    while(q--){
        solve();
    }
    return 0;
}
