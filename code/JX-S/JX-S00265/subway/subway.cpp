#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
    ll res=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        res=10*res+ch-'0';
        ch=getchar();
    }
    return res*f;
}
void outt(ll x){
    if(x<0){
        x=-x;
    }
    char ch=x%10+'0';
    if(x>=10)outt(x/10);
    putchar(ch);
}
const ll M=5e5+5;
const ll N=505;
ll c,n,m,d,q;
ll w[M];
ll dis[N][N];
vector<pair<ll,ll> > e[M];//subway station `s line and time
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read();
    n=read();
    m=read();
    d=read();
    q=read();
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(i==j){
                dis[i][j]=dis[j][i]=0;
            }
            else{
                dis[i][j]=dis[j][i]=(1ll<<57);
            }
        }
    }
    for(int i=1;i<=m;i++){
        w[i]=read();
    }
    for(ll i=1;i<=n;i++){
        ll k=read();
        for(ll j=1;j<=k;j++){
            ll a=read();
            ll t=read();
            for(ll cnt=0;cnt<e[a].size();cnt++){
                ll x=e[a][cnt].first;
                ll timm=e[a][cnt].second;
                dis[x][i]=min(dis[x][i],t+timm);
                dis[i][x]=dis[x][i];
            }
            e[a].push_back({i,t});//max num is 20
        }
    }
    for(ll K=1;K<=n;K++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][K]+dis[K][j]);
                dis[j][i]=dis[i][j];
            }
        }
    }
    while(q--){
        ll ans=(1ll<<57);
        ll x=read(),y=read();
        for(int i=0;i<e[x].size();i++){
            for(int j=0;j<e[y].size();j++){
                int u=e[x][i].first;
                int v=e[y][j].first;
                ll w=e[x][i].second+e[y][j].second;
                ans=min(ans,dis[u][v]+w);
            }
        }
        outt(ans+w[x]+w[y]);
        putchar('\n');
    }
    return 0;
}

