#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll read();
inline void wt(ll);
struct P{
    char ch;
    ll lng;
};
ll n,a[200005];
P l[200005],r[200005];
char c[200005];
ll cntdif,cnt1,cnt2,cnt3,cnt4,cnt5;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    n = read();
    for(register ll i = 1;i <= n;++i){
        a[i] = read();
        c[i] = getchar();
        cnt1 += a[i];
    }
    cnt2 = cnt1 / 2;
    for(register ll i = 1;cnt3 <= cnt2;++i){
        if(cnt3 + a[i] >= cnt2){
            l[++cnt4] = {c[i],cnt2 - cnt3 + 1};
            break;
        }else{
            l[++cnt4] = {c[i],a[i]};
            cnt3 += a[i];
        }
    }
    cnt3 = 0;
    for(register ll i = n;cnt3 <= cnt2;--i){
        if(cnt3 + a[i] >= cnt2){
            r[++cnt5] = {c[i],cnt2 - cnt3 + 1};
            break;
        }else{
            r[++cnt5] = {c[i],a[i]};
            cnt3 += a[i];
        }
    }
    for(register ll i = 1,j = 1;i <= cnt4 && j <= cnt5;){
        if(l[i].lng < r[j].lng){
            ll x = l[i].lng;
            if(l[i].ch != r[j].ch){
                cntdif += x;
            }
            ++i;
            r[j].lng -= x;
        }else if(l[i].lng == r[j].lng){
            if(l[i].ch != r[j].ch){
                cntdif += l[i].lng;
            }
            ++i,++j;
        }else{
            ll x = r[j].lng;
            if(l[i].ch != r[j].ch){
                cntdif += x;
            }
            ++j;
            l[i].lng -= x;
        }
    }
    if(cntdif && !(cnt1 & 1)) cntdif--;
    wt(cntdif);
    fclose(stdin);
    fclose(stdout);
    return 0;
}

inline ll read(){
    register ll r;register bool f = 1;register char c;
    while((c = getchar()) && !isdigit(c)) if(c == '-') f^=1;
    r = (c ^ 48);
    while((c = getchar()) && isdigit(c)) r = (r << 3) + (r << 1) + (c ^ 48);
    return r * (f ? 1 : -1);
}
inline void wt(ll n){
    if(n < 0) putchar('-'),n = -n;
    if(n > 9) wt(n / 10);
    putchar(n % 10 + 48);
}
