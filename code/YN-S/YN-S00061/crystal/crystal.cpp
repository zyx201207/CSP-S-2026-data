#include<bits/stdc++.h>
using namespace std;
constexpr long long MAXN=5e5+1000,INF=0x3f3f3f3f3f3f3f3f;

long long n,m,rl,rr,rmid,ans;
long long cys[MAXN],sumcs[MAXN];

bool check(long long x);

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    scanf("%lld %lld",&n,&m);
    for (int i=1;i<=n;i++) scanf("%lld",&cys[i]);
    sort(cys+1,cys+1+n);
    for (int i=1;i<=n;i++) sumcs[i]=sumcs[i-1]+cys[i];
    rl=0,rr=n;
    while (rl<rr){
        rmid=(rl+rr+1)/2;
        if (check(rmid)) rl=rmid;
        else rr=rmid-1;
    }
    printf("%lld\n",rl);
    return 0;
}

bool check(long long x){
    long long minops=INF;
    for (int i=x;i<=n;i++) minops=min(minops,cys[i]*x-(sumcs[i]-sumcs[i-x+1-1]));
    return minops<=m;
}