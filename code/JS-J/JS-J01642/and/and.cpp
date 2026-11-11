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
struct lian{
    ll data , next , pro , tao;
} ji[200005];
ll n , m , a[200005] , maxx , num , cnt , cnt1 , jia , z , ans;
int main(){
    freopen("and.in" , "r" , stdin);
    freopen("and.out" , "w" , stdout);
    n = read();
    m = read();
    for(ll i = 1;i <= n;i ++){
        a[i] = read();
        maxx = max(maxx , a[i]);
    }
    while(maxx){
        maxx = maxx >> 1;
        num ++;
    }
    while(1){
        cnt = 0;
        for(ll i = 1;i <= n;i ++){
            if((a[i] >> num - 1) == 1){
                ji[cnt].pro = cnt - 1;
                ji[cnt].next = ++ cnt;
                ji[cnt].data = a[i];
            }
        }
        num --;
        if(cnt >= m) break;
    }
    while(cnt > m){
        jia ++;
        cnt1 = cnt;
        for(ll i = 1;i <= cnt;i ++){
            if((ji[i].data >> num - 1) != 1){
                ji[ji[i].pro].next = ji[i].next;
                ji[ji[i].next].pro = ji[i].pro;
                ji[i].tao = jia;
                cnt1 --;
            }
        }
        if(cnt1 < m){
            for(ll i = 1;i <= cnt;i ++){
                if(ji[i].tao == jia){
                    ji[ji[i].pro].next = i;
                    ji[ji[i].next].pro = i;
                }
            }
        }
        else cnt = cnt1;
    }
    z = ji[0].next;
    ans = ji[z].data;
    while(cnt --){
        ans &= ji[z].data;
        z = ji[z].next;
    }
    print(ans);
    return 0;
}