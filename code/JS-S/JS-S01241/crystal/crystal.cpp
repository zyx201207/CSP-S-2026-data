#include <bits/stdc++.h>
using namespace std;
typedef int re;typedef long long ll;
ll n,m,a[500005];
bool cmp(ll a,ll b){
    return a < b;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for (re i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a + 1,a + n + 1,cmp);
    ll tt = 0,l = 0,mx = 1;
    for (re i = 2;i <= n;i++){
        tt += (i - 1) * (a[i] - a[i - 1]);
        if (tt >= m){
            while (tt > m) tt -= (a[i] - a[++l]);
        }
        mx = max(mx,i - l);
    }cout << mx;
    return 0;
}

