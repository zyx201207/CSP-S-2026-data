#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;
struct pltfm{
    ll index,cst;
};
ll c,n,m,d,T;
ll w[500005],k[505],dis[505][505],t[505][500005];
vector<pltfm> v[505];
vector<ll> bltsbw[505];
bool cmp(pltfm a,pltfm b){
    return a.index<b.index;
}
ll minll(ll a,ll b){
    if(a<=b) return a;
    return b;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>T;
    for(ll i=1;i<=m;i++) cin>>w[i];
    for(ll i=1;i<=n;i++){
        cin>>k[i];
        for(ll j=1;j<=k[i];j++){
            ll x,y;cin>>x>>y;
            t[i][x]=y;
            bltsbw[x].push_back(i);
            v[i].push_back({x,y});
        }
        sort(v[i].begin(),v[i].end(),cmp);
    }
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            dis[i][j]=LLONG_MAX;
        }
        dis[i][i]=0;
    }
    for(ll i=1;i<n;i++){
        for(ll j=i+1;j<=n;j++){
            ll ipos=0,jpos=0;
            while(ipos<=v[i].size()-1&&jpos<=v[j].size()-1){
                ll pa=v[i][ipos].index,pb=v[j][jpos].index;
                if(pa==pb){
                    ll CST=v[i][ipos].cst+v[j][jpos].cst;
                    dis[i][j]=minll(dis[i][j],CST);
                    dis[j][i]=dis[i][j];
                    ipos++;jpos++;
                }
                if(pa<pb){
                    ipos++;
                }
                if(pa>pb){
                    jpos++;
                }
            }
        }
    }
    for(ll k=1;k<=n;k++){
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=n;j++){
                dis[i][j]=minll(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(T--){
        ll st,en,ans=LLONG_MAX;cin>>st>>en;
        for(ll i=0;i<bltsbw[st].size();i++){
            for(ll j=0;j<bltsbw[en].size();j++){
                ll sbws=bltsbw[st][i],sbwe=bltsbw[en][j];
                ans=minll(ans,t[sbws][st]+dis[sbws][sbwe]+t[sbwe][en]);
            }
        }
        ans+=(w[st]+w[en]);
        cout<<ans<<endl;
    }
    return 0;
}
