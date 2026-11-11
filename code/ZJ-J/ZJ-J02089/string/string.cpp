#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
const int maxn = 1e6 + 1000;
ll a[maxn];
char c[maxn];
ll ans = 0;
// string s;
// T2 9.07 9.42 all-AC
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    scanf("%lld",&n);
    for(ll i = 1;i <= n;i++){
        scanf("%lld %c",&a[i],&c[i]);
    }
    ll firsti = 1;
    ll endi = n;
    // 双指针

    // 1,2-AC 3-TLE
    // while (firsti != endi)
    // {
    //     if(a[firsti] == 0){
    //         firsti++;
    //     }else if(a[endi] == 0){
    //         endi--;
    //     }else if(c[firsti] != c[endi]){
    //         ans++;
    //         a[firsti]--;
    //         a[endi]--;
    //     }else{
    //         a[firsti]--;
    //         a[endi]--;
    //     }
        
    //     /* code */
    // }

    while (firsti != endi)
    {
        if(a[firsti] == 0){
            firsti++;
        }else if(a[endi] == 0){
            endi--;
        }else if(c[firsti] == c[endi]){
            if(a[endi] == a[firsti]){
                firsti++;
                endi--;
                continue;
            }
            ll mini = min(a[firsti],a[endi]);
            a[firsti] -= mini;
            a[endi] -= mini;
        }else{// c[firsti] != c[endi]
            ll mini = min(a[firsti],a[endi]);
            ans += mini;
            a[firsti] -= mini;
            a[endi] -= mini;
        }
        /* code */
    }
    
    printf("%lld",ans);
    return 0;
}