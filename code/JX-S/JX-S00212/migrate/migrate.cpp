#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define str string
#define lf double
void op(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
}
const ll N=2e5+10;
ll c,t;
ll n,d;
ll x[N];
vector<ll>E[N];

ll cnt,mb,zd;
void dfs(ll dq,ll bs){
    if(dq>zd)return;
    if(dq==zd){
        if(bs==mb)++cnt;
        return;
    }
    if(cnt>2)return;
    if(bs>=mb)return;
    for(ll v=E[dq].size()-1;v>=0;--v){
        dfs(E[dq][v],bs+1);
        if(cnt>2)return;
    }
    return;
}
ll meow(ll s,ll e,ll hzy){
    cnt=0;mb=hzy;zd=e;
    dfs(s,0);
    return cnt;
}

bool check(ll s,ll e){
    ll min_step=0;
    ll dq=s;
    while(x[dq]<x[e]){
        if(E[dq].size()==0)return 0;
        dq=E[dq][E[dq].size()-1];
        ++min_step;
    }
    ll ff=meow(s,e,min_step);
    if(ff==2)return 1;
    else return 0;
}
int main(){
    op();
    scanf("%lld%lld",&c,&t);
    while(t--){
        for(ll i=0;i<=200005;++i){
            E[i].clear();
        }
        ll ans=0;
        scanf("%lld%lld",&n,&d);
        for(ll i=1;i<=n;++i){
            scanf("%lld",&x[i]);
        }
        for(ll i=1;i<=n;++i){
            for(ll j=i+1;j<=n;++j){
                if(x[j]-x[i]<=d){
                    E[i].push_back(j);
                }
            }
        }
        for(ll i=1;i<=n;++i){
            for(ll j=i+1;j<=n;++j){
                bool bj=check(i,j);
                ans+=bj;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
/*
abcdefghijklmnopqrstuvwxyz1234567890!@#$%^&*()~`_+-={}[]|\:";'<>.
*/
