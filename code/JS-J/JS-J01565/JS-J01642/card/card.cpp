#include<bits/stdc++.h>
#define ll long long
#define in inline
#define get getchar()
using namespace std;
in ll read(){
    ll x = 0 , f = 1;
    char ch = get;
    while(ch < '0' || ch > '9'){
        if(ch = '-') f = -1;
        ch = get;
    }
    while(ch >= '0' && ch <= '9'){
        x = (x << 3) + (x << 1) + (ch - '0');
        ch = get;
    }
    return x * f;
}
in void print(ll x){
    if(x > 9) print(x / 10);
    putchar(x % 10 + '0');
}
queue<ll> cnt[300005];
ll n , m , ans[300005] , a[500005];
int main(){
    freopen("card.in" , "r" , stdin);
    freopen("card.out" , "w" , stdout);
    n = read();
    m = read();
    for(ll i = 1;i <= n;i ++) a[i] = read();
    for(ll i = 1;i <= n;i ++){
        for(ll j = i;j <= n;j ++){
            cnt[a[j]].push(j);
            if(cnt[a[j]].size() == 2){
                cnt[a[j]].pop();
                ll z = cnt[a[j]].back();
                cnt[a[j]].pop();
                cnt[a[j]].push(j);
                for(ll h = z;h < j;h ++) cnt[a[h]].pop();
            }
        }
        for(ll j = 1;j <= m;j ++){
            if(cnt[j].size()){
                ans[j] ++;
                cnt[j].pop();
            }
        }
    }
    for(ll j = 1;j <= m;j ++){
        print(ans[j]);   
    }
    return 0;
}