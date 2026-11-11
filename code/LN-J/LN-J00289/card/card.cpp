#include <bits/stdc++.h>

using namespace std;
using ll=long long;
const ll N=5e5+5,M=3e5+5;
ll a[N],CNT[M],cnt[M],s[N];

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ll n,m;
    scanf("%lld %lld",&n,&m);
    for(ll i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    for(ll i=1;i<=n;i++){
        memset(cnt,0,sizeof(cnt));
        memset(s,0,sizeof(s));
        ll tot=0;
        for(ll j=i;j<=n;j++){
            if(!cnt[a[j]]){
                s[++tot]=a[j];
                cnt[a[j]]++;
            }else{
                for(ll k=tot;k>=1;k--){
                    if(s[k]==a[j]){
                        tot=k;
                        break;
                    }else{
                        cnt[s[k]]--;
                    }
                }

            }
        }
        for(ll j=1;j<=tot;j++)CNT[s[j]]++;
    }
    for(ll i=1;i<m;i++){
            printf("%lld ",CNT[i]);
    }
    printf("%lld\n",CNT[m]);
    return 0;
}
