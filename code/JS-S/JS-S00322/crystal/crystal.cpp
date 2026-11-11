#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;
ll n,m,ans = 1,sum,a[N],q[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a + 1,a + n + 1);
    for (int i = 1;i <= n;i++){
        q[i] = q[i - 1] + a[i];
    }
    int p = 1;
    for (int i = 2;i <= n;i++){
        while (p < i && a[i] * i - q[i - 1] > m) p++;
        ans = max(ans,1ll * i - p + 1);
    }
    cout << ans;
    return 0;
}
