#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500005],n,m,s[500005];
int main(){
    bool flag1 = true,flag2 = true;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    cin >> a[1];
    for (ll i = 2;i <= n;i++){
        cin >> a[i];
        if ((a[i] - a[i - 1]) != (a[2] - a[1])){
            flag2 = false;
        }
        if (a[i] != i){
            flag1 = false;
        }
    }
    sort(a + 1,a + n + 1);
    s[1] = 0;
    for (ll i = 2;i <= n;i++){
        s[i] = a[i] - a[i - 1] + s[i - 1];
    }
    if (flag1){
        ll tot = 0,k = 1;
        while (tot <= m){
            tot += k;
            k++;
        }
        k --;
        cout << k;
        return 0;
    }
    if (flag2){
        ll tot = 0,k = a[2] - a[1];
        while (tot <= m){
            tot += k;
            k = k + a[2] - a[1];
        }
        k = (k / 2) - 1;
        cout << k;
        return 0;
    }
    ll maxn = -1;
    for (ll i = 1;i <= n;i++){
        for (ll j = i + 1;j <= n;j++){
            if ((s[j] - s[i] + 1) <= m){
                ll num = j - i + 1;
                if (num > maxn){
                    maxn = num;
                }
            }
        }
    }
    cout << maxn;
    return 0;
}
