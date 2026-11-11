#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5+5;
int n;
ll a[N],pre[N],m,ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    for (int i = 1;i <= n;i++) {
        pre[i] = pre[i-1] + a[i];
    }
    int j = 1;
    for (int i = 1;i <= n;i++) {
        while (pre[j] - pre[i-1] + m >= a[j] * (j-i+1) && j <= n) {
            j++;
        }
        ll k = j-i;
        ans = max(ans,k);
        if (j >= n) break;
    }
    cout << ans;
    return 0;
}
