#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,m,ans = 0;
LL a[100000005] = {0};
LL c[100000005] = {0};
long long p(LL x,LL l,LL r){
    for (int i = l;i <= r;i++){
            for (int j = 1;j <= r - l;j++){
                x = x + c[i] * j;
            }
        }
    return x;
}//panduan cong l kaishi yi r wei hebing mubiao yao +duoshaoci
void dg(LL l,LL r,LL s){
    LL cnt = s;
    LL mid = l + r >> 1;
    LL t = 0;
    LL g = 0;
    t = p(t,l,mid);
    g = p(g,mid,r);
    if (t <= m && g > m){
        if (s < cnt){
            cnt = mid - l + 1;
            dg(l,mid + l >> 1,cnt);
        }
    }
    else if (t > m && g <= m){
        if (s < cnt){
            cnt = r - mid + 1;
            dg(mid >> 1,r,cnt);
        }
    }
    else if (t < m && g < m && t != g){
        if (t > g){
            if (s < cnt){
                cnt = mid - l + 1;
                dg(l,mid + l >> 1,cnt);
            }
        }
        if (t < g){
            if (s < cnt){
                cnt = r - mid + 1;
                dg(mid >> 1,r,cnt);
            }
        }
    }

    else if (t == g){
        dg(l,mid,cnt);
    }
    if (m < cnt) return;
    if (m >= cnt) {
        cout << cnt;
        return;
    }

}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    c[0] = 0;
    c[1] = 0;
    for (int i = 1;i <= n;i++){
        cin >> a[i];
        c[i] = a[i] - a[i - 1];

    }
    dg(1,n + 1,0);

    return 0;

}
