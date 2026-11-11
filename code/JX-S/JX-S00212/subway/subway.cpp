#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define str string
#define lf double
typedef pair<ll,ll> pll;
void op(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
}
const ll N=500+10;
const ll M=5e5+25;
const ll INF=4e18;

ll c,n,m,d,q;
struct station{
    ll w;
    ll road_jg;
    vector<pll> xl;
    ll bh;
}a[M];
struct road{
    ll k;
    vector<pll> xl;
    ll bh;
}b[N];

ll floyd[1003][1003];
void input(){
    for(ll i=1;i<=m;++i){
        scanf("%lld",&a[i].w);
        a[i].bh=i;
    }
    for(ll i=1;i<=n;++i){
        scanf("%lld",&b[i].k);
        for(ll j=1,x,y;j<=b[i].k;++j){
            scanf("%lld%lld",&x,&y);
            a[x].xl.push_back(make_pair(i,y));
            b[i].xl.push_back(make_pair(x,y));
        }
    }
    return;
}
void ycl(){
    for(ll i=1;i<=m;++i){
        for(ll j=1;j<=m;++j){
            if(i==j)continue;
            else floyd[i][j]=INF;
        }
    }
    for(ll i=1;i<=n;++i){
        for(ll j=0;j<b[i].k;++j){
            for(ll k=j+1;k<b[i].k;++k){
                floyd[b[i].xl[j].first][b[i].xl[k].first]=min(b[i].xl[j].second+b[i].xl[k].second,floyd[b[i].xl[j].first][b[i].xl[k].first]);
            }
        }
    }
    for(ll i=1;i<=m;++i){
        for(ll j=1;j<=m;++j){
            for(ll k=1;k<=m;++k){
                floyd[k][j]=floyd[j][k]=min(floyd[i][j]+floyd[i][k],floyd[j][k]);
            }
        }
    }
    return;
}
void solve1(){
    input();
    ycl();
    while(q--){
        ll Start,End;
        scanf("%lld%lld",&Start,&End);
        printf("%lld\n",floyd[Start][End]+a[Start].w+a[End].w);
    }
    return;
}

int main(){
    op();
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    if(0<=c&&c<=11){
        solve1();
        return 0;
    }else{
        input();
        while(q--){
            ll Start,End;
            scanf("%lld%lld",&Start,&End);
            printf("%lld\n",a[Start].w+a[End].w+a[Start].xl[0].second+a[End].xl[0].second);
        }
    }
    return 0;
}
/*
abcdefghijklmnopqrstuvwxyz1234567890!@#$%^&*()~`_+-={}[]|\:";'<>.
*/
