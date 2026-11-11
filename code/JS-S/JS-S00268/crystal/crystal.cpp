#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 5e5+5;

ll in() {
    ll x = 0,f = 1;int c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') x = x*10+c-'0',c = getchar();
    return f*x;
}

int n;ll m;
ll a[N],s[N];

int main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n = in(),m = in();
    for (int i = 1;i <= n;i ++) a[i] = in();
    sort(a+1,a+n+1);
    for (int i = 1;i <= n;i ++) s[i] = s[i-1]+a[i];
    int ans = 0;
    for (int i = 2;i <= n;i ++) {
        int l = 1,r = i-1;
        int res;
        while (l <= r) {
            int mid = (l+r)>>1;
            ll cost = a[i]*(i-1-mid+1)-(s[i-1]-s[mid-1]);
            if (cost <= m) res = mid,r = mid-1;
            else l = mid+1;
        }
        ans = max(ans,i-res+1);
    }
    printf("%d",ans);
}
