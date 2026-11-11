#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define rf(i,a,b) for(int i=(a);i>=(b);--i)
#define max_eq(a,b) ((a)=(a)>(b)? (a):(b))
#define min_eq(a,b) ((a)=(a)<(b)? (a):(b))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(),(x).end()

const int N=2e6+5;

int n,nxt[N],pre[N],a[N],tot;
ll d,x[N];

void solve(){
    scanf("%d%lld",&n,&d);
    F(i,1,n) scanf("%lld",&x[i]);
    x[n+1]=3e18, x[0]=-3e18;
    F(i,1,n){
        nxt[i]=upper_bound(x+i,x+n+1,x[i]+d)-x-1;
        pre[i]=lower_bound(x+1,x+i,x[i]-d)-x;
        // cerr<<i<<' '<<nxt[i]<<' '<<pre[i]<<endl;
    }
    ll ans=0;
    F(i,1,n){
        tot=0; int x=i;
        while(x!=nxt[x]) a[++tot]=x, x=nxt[x];
        a[++tot]=x;
        if(tot==1) continue;
        int lst=2;
        // cerr<<"*"<<a[1]<<' '<<a[2]<<endl;
        F(j,a[2]+1,n){
            if(pre[j]==a[lst]-1&&(pre[pre[j]]<i||pre[pre[j]]==a[lst-1])) ans++;//,cerr<<i<<' '<<j<<endl;
            if(lst<tot&&a[lst+1]==j) lst++;
        }
    }
    printf("%lld\n",ans);
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,T;
    scanf("%d%d",&c,&T);
    while(T--) solve();
    return 0;
}

// g++ my.cpp -o my -std=c++14 -O2 -Wall -Wextra -Wshadow -Wconversion -fsanitize=address,undefined
// ulimit -s 524288
// /usr/bin/time -v ./my
// g++ my.cpp -o my -std=c++14 -O2 -Wall