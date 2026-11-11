#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mp make_pair
#define fi first
#define se second
#define pii pair<int,int>

#define FILENAME "migrate"

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

const int N=5005;

int n;
ll d,x[N];

void solve() {
    n=read();d=read();
    for(int i=1;i<=n;i++) x[i]=read();
    ll ans=0;
    for(int r=4;r<=n;r++) {
        int f[N]={0},cnt[N]={0};
        ll s[N]={0};
        s[r]=f[r]=1;
        for(int l=r-1,k=r;l>=1;l--) {
            while(x[k]-x[l]>d) k--;
            cnt[l]=cnt[k]+1;
            // cerr<<"l"<<" : "<<cnt[l]<<endl;
        }
        for(int l=r-1,k=r,p=r;l>=1;l--) {
            while(x[k]-x[l]>d) k--;
            while(cnt[p-1]<cnt[l]) p--;
            // cerr<<p<<' '<<k<<"   "<<l<<' '<<r<<endl;

            // for(int _=p;_<=k;_++) f[l]+=f[_];

            if(k>=p) f[l]=s[p]-s[k+1];
            else f[l]=0;
            // cerr<<f[l]<<endl;
            if(f[l]==2) ans++;
            s[l]=f[l]+s[l+1];
        }
    }
    write(ans);
}

int main() {
    freopen(FILENAME".in","r",stdin);
    freopen(FILENAME".out","w",stdout);
    int T=1;
    // ios::sync_with_stdio(0);
    // cin.tie(0);cout.tie(0);
    // cin>>T;
    ///////////////////////////////
    T=read(); T=read();
    while(T--) solve();
    return 0;
}

// g++ ./migrate.cpp -o ./migrate -O2 -std=c++14 -fsanitize=address,undefined -Wall -Wextra -Wconversion
