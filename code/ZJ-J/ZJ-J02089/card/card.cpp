#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n,m;
const int maxn = 1e6 + 100;
ll a[maxn];

struct card
{
    bool ison = false;
    ll id = 0;
    /* data */
};

// T4 11.17
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    scanf("%lld %lld",&n,&m);
    for(int i = 1;i <= n;i++){
        scanf("%lld",&a[i]);
        if(a[i] > m){
            a[i] = m + 1;
        }
    }
    ll ans[m + 2];
    for(ll i = 1;i <= m + 1;i++){
        ans[i] = 0;
    }
    for(ll i = 1;i <= n;i++){
        card tmp[m + 10];
        ll flag = 1;
        for(ll j = 1;j <= n;j++){
            if(tmp[a[j]].ison == false){
                tmp[a[j]].ison = true;
                tmp[a[j]].id = flag;
                flag++;
            }else{
                for(ll k = tmp[a[j]].id;k <= j;k++){
                    tmp[a[k]].ison = false;
                    tmp[a[k]].id = 0;
                }
                flag = tmp[a[j]].id;
            }
        }
        for(ll j = 1;j <= m;j++){
            if(tmp[a[j]].ison == true){
                ans[a[j]]++;
            }
        }
    }
    for(ll i = 1;i <= m;i++){
        printf("%lld ",ans[i]);
    }
    return 0;
}