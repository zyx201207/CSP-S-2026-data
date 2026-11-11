#define FOR(a,b,c) for(ll a=(b);a<=(c);a++)
#define ROF(a,b,c) for(ll a=(b);a>=(c);a--)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>pll;
typedef pair<int,int>pii;
typedef unsigned long long ull;
const ll MOD=1,MAXN=2222222;
ll c,t,n,d,a[MAXN],now,cnt1[MAXN],cnt2[MAXN],pos1[MAXN],pos2[MAXN],cnt3[MAXN],cnt4[MAXN],ans,pos[MAXN];
int main(){
    freopen("migrate2.in","r",stdin);
    freopen("migrate2.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    while(t--){
        ans=0;
        scanf("%lld%lld",&n,&d);
        FOR(i,1,n) cnt1[i]=cnt2[i]=cnt3[i]=cnt4[i]=0;
        FOR(i,1,n) scanf("%lld",a+i);
        now=1;
        FOR(i,1,n){
            while(a[i]-a[now]>d) now++;
            if(now<i-1) cnt1[now]++;
            cnt3[now]++;
            pos1[now]=i;
            //pos[i]=now;
        }
        now=n;
        ROF(i,n,1){
            while(a[now]-a[i]>d) now--;
            if(now>i+1)cnt2[now]++;
            cnt4[now]++;
            pos2[now]=i;
        }
        FOR(i,2,n){
            //if(pos[i]!=i-1)
            ans+=cnt2[i]*cnt1[i-1]*(cnt3[pos[i-1]]+1)*(cnt4[pos[i]]+1);
        }
        printf("%lld\n",ans);

    }
    return 0;
}
