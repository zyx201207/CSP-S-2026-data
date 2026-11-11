#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n,m;
const int maxn = 1e6 + 10;
ll a[maxn];

ll andd(ll x,ll y){
    ll tmp = 0;
    ll ing = 2;
    while(x >= ing && y >= ing){
        if(x % ing == 1 && y % ing == 1){
            tmp += ing;
            x -= ing;
            y -= ing;
        }
        ing = ing * 2;
    }
    if(x % 2 == 1 && y % 2 == 1){
        tmp++;
    }
    // if(x % ing == 1 && y % ing == 1){
    //     tmp += (ing / 2);
    // }
    return tmp;
}// ready for dfs
// ll andd(ll x,ll round){
//     ll ing = 2;
//     ll tmp = 0;
//     ll y;
//     // if(round < m){
//     //     y = andd(x,round + 1);
//     // }
//     ll mmax = 0;
//     while(x >= ing && y >= ing){
//         if(x % ing == 1 && y % ing == 1){
//             tmp += (ing / 2);
//         }
//         ing = ing * 2;
//     }
//     return max(mmax,andd(x,round + 1));
// }// ready for dfs
ll all(ll in,ll round,ll key){
    in = andd(in,a[key + round]);
    if(round < m - 1){
        round++;
        in = all(in,round,key);
    }
    return in;
}
bool cmp(ll x,ll y){
    return x > y;
}
// T3 9.43 11.16

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    scanf("%lld %lld",&n,&m);
    for(ll i = 1;i <= n;i++){
        scanf("%lld",&a[i]);
    }
    // to 2 first

    // ll ttt = 2;
    // for(int i = 1;i <= 30;i++){
    //     ttt = ttt * 2;
    // }
    // printf("%lld",ttt);
    // max-a[i]2 ^ 30 == 21e --> all-ll
    // and no save 2

    // ttt
    sort(a + 1,a + n + 1,cmp);
    // // ll ans = 0;
    // // for(ll i = 1;i <= n;i++){
    // //     ans = max(ans,all(a[i],1,i));
    // //     printf("%lld ",a[i]);
    // // }
    // // printf("%lld",ans);
    // // printf("%lld",andd(3,31));

    printf("%lld",a[m]);
    return 0;
}