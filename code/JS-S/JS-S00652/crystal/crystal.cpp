#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1e5 + 9;
int n,ans,flag,len;
long long m,xx;
long long a[5 * MAXN];

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> m;flag = n;
    for(int i = 1;i <= n;i ++) cin >> a[i];
    sort(a + 1,a + n + 1);
    xx = 0;
    while(xx < m && flag >= 1){
        xx += a[n] - a[--flag];
    }
    if(xx > m) xx -= a[n] - a[flag ++];
    ans = len = n - flag;
    for(int i = n - 1;i >= 1;i --){
        if(ans >= i) break;
        xx -= (len --) * (a[i + 1] - a[i]);
        while(xx < m && flag >= 1){
            xx += a[i] - a[--flag];
        }
        if(xx > m) xx -= a[n] - a[flag ++];
        len = i - flag;
        ans = max(ans,len);

    }
    if(ans != 0) cout << ans + 1;
    else cout << 0;

    return 0;
}

