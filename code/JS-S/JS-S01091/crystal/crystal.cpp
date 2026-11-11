#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int a[N],ans,n,m,cf[N],cal[N];
inline int f_rd(){
    register int r = 0;
    register bool f = 1;
    register char c;
    while((c = getchar()) && (!isdigit(c))) if(c == '-') f ^= 1;
    r = (c^48);
    while((c = getchar()) && (isdigit(c))) r = r*10 + (c^48);
    return r * (f ? 1 : -1);
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    n=f_rd();m=f_rd();
    for(int i = 1;i <= n;i++){
        a[i] = f_rd();
    }sort(a+1,a+n+1);
    for(int i = 2;i <= n;i++){
        cf[i] = (a[i]-a[i-1]);
        cal[i] = cal[i-1]+cf[i]*(i-1);
    }for(int ans = 1;ans <= sizeof(cal);ans++){
        //cout << cal[ans] << ' ';
        if(cal[ans] > m) {cout << ans - 1 << endl;break;}
    }
}
