#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
ll n,ans,L,a[N],sum[N];
char cn[N];

ll f(ll cl,ll cr,char ch){
    ll res = 0;
    cl = L - cl + 1;
    cr = L - cr + 1;
    ll zl,zr;
    ll l = 1,r = n,mid,ans;
    swap(cl,cr);
    while (l <= r){
        mid = (l + r) >> 1;
        if (sum[mid] <= cl){
            ans = mid;
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    zl = l;
    l = 1,r = n;
    while (l <= r){
        mid = (l + r) >> 1;
        if (sum[mid] >= cr){
            ans = mid;
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }
    zr = r;
    swap(zl,zr);
    //cout << zl << ' ' << zr << '\n';
    for (int i = zl;i <= zr;i++){
        int len = 0;
        if (i == zl) len = sum[i] - cl + 1;
        else if (i == zr) len = cr - sum[i - 1];
        else len = a[i];
        if (cn[i] != ch) res += len;
    }
    return res;
}

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cout.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 1;i <= n;i++){
        cin >> a[i] >> cn[i];
        L += a[i];
        sum[i] = L;
    }
    for (int i = 1;i <= n;i++){
        if (i >= L / 2) break;
        //cout << i << ' ' << f(sum[i],min(sum[i],L / 2),cn[i]) << '\n';
        ans += f(sum[i - 1] + 1,min(sum[i],L / 2),cn[i]);
    }
    cout << ans;
    return 0;
}
