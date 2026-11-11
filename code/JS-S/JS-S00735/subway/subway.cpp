#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define pii pair<int,int>

#define FILENAME "subway"

ll read() {
    char ch=getchar_unlocked(); bool f=0; ll ret=0;
    while(ch<'0'||ch>'9') f=f||(ch=='-'),ch=getchar_unlocked();
    while(ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar_unlocked();
    return ret*(f?-1:1);
}

void write(ll v,char step='\n') {
    if(v<0) putchar_unlocked('-'),v=-v;
    if(v==0) putchar_unlocked('0');
    char s[30]; int tp=0;
    while(v) s[tp++]=v%10+'0',v/=10;
    while(tp--) putchar_unlocked(s[tp]);
    putchar_unlocked(step);
}

void chmin(ll &x,ll y) {
    x=min(x,y);
}

const int N=505;
const int M=5e5+5;

int c,n,m,d,q;
vector<pii> zt[M];
ll xl[N][N];
ll w[M];

void solve() {
    c=read(); n=read(); m=read(); d=read(); q=read();
    for(int i=1;i<=m;i++) w[i]=read();
    for(int i=1,k,a,t;i<=n;i++) {
        k=read();
        for(int j=1;j<=k;j++) {
            a=read(); t=read();
            zt[a].eb(mp(i,t));
        }
    }
    memset(xl,0x3f,sizeof(xl));
    for(int i=1;i<=m;i++) {
        for(int j=0;j<zt[i].size();j++) {
            for(int k=0;k<zt[i].size();k++) {
                chmin(xl[zt[i][j].fi][zt[i][k].fi],zt[i][j].se+zt[i][k].se);
                chmin(xl[zt[i][k].fi][zt[i][j].fi],zt[i][j].se+zt[i][k].se);
            }
        }
    }
    for(int i=1;i<=n;i++) xl[i][i]=0;
    // for(int i=1;i<=n;i++) {
    //     for(int j=1;j<=n;j++) {
    //         cerr<<xl[i][j]<<' ';
    //     }
    //     cerr<<endl;
    // }
    for(int k=1;k<=n;k++) {
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                chmin(xl[i][j],xl[i][k]+xl[k][j]);
            }
        }
    }
    for(int _=1,x,y;_<=q;_++) {
        x=read();y=read();
        ll ans=1e18;
        for(auto u:zt[x]) {
            for(auto v:zt[y]) {
                chmin(ans,xl[u.fi][v.fi]+u.se+v.se);
            }
        }
        write(ans+w[x]+w[y]);
    }
    // cerr<<xl[1][2]<<endl;
}

int main() {
    freopen(FILENAME".in","r",stdin);
    freopen(FILENAME".out","w",stdout);
    int T=1;
    // ios::sync_with_stdio(0);
    // cin.tie(0);cout.tie(0);
    // cin>>T;
    ///////////////////////////////
    // T=read();
    while(T--) solve();
    return 0;
}

// g++ ./subway.cpp -o ./subway -O2 -std=c++14 -fsanitize=address,undefined -Wall -Wextra -Wconversion
