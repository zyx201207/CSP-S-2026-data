#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll w[500005],dis[505][505],f[505][505];
vector<pair<ll,ll>>g[500005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ll c,n,m,d,q;
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for(ll i=1;i<=m;i++)scanf("%lld",&w[i]);
    for(ll i=1;i<=n;i++){
        ll x;
        scanf("%lld",&x);
        for(ll j=1;j<=x;j++){
            ll v,w1;
            scanf("%lld%lld",&v,&w1);
            //f[i].push_back({v,w1});
            g[v].push_back({i,w1});
        }
    }
    for(ll i=1;i<=m;i++){
        for(ll j=0;j<g[i].size()-1;j++){
            for(ll k=j+1;k<g[i].size();k++){
                f[g[i][j].first][g[i][k].first]=g[i][j].second+g[i][k].second;
                f[g[i][k].first][g[i][j].first]=g[i][j].second+g[i][k].second;
            }
        }
    }
    //for(int i=1;i<=n;i++){
    //    for(int j=1;j<=n;j++)cout<<f[i][j]<<" ";
    //    cout<<endl;
    //}
    //cout<<endl;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)dis[i][j]=LLONG_MAX;
    for(ll i=1;i<=n;i++)dis[i][i]=0;
    for(ll i=1;i<=n;i++)
        for(ll j=1;j<=n;j++)
            if(f[i][j]!=0)dis[i][j]=f[i][j];
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            for(ll k=1;k<=n;k++){
                if(dis[i][k]!=LLONG_MAX && f[k][j]!=0){
                    dis[i][j]=min(dis[i][j],dis[i][k]+f[k][j]);
                    dis[j][i]=min(dis[j][i],dis[i][j]);
                }
            }
        }
    }/*
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)cout<<dis[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;*/
    for(ll i=1;i<=q;i++){
        ll x,y,Min=INT_MAX;
        scanf("%lld%lld",&x,&y);
        for(ll j=0;j<g[x].size();j++){
            for(ll k=0;k<g[y].size();k++){
                Min=min(Min,dis[g[x][j].first][g[y][k].first]+g[x][j].second+g[y][k].second);
                //cout<<g[x][j].first<<" "<<g[y][k].first<<" "<<Min<<" "<<dis[g[x][j].first][g[y][k].first]+g[x][j].second+g[y][j].second<<" "<<g[x][j].second<<" "<<g[y][j].second<<endl;
            }
        }
        printf("%lld\n",Min+w[x]+w[y]);
    }
    return 0;
}
