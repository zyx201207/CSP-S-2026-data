#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2*100000+5;
ll a[N];
char c[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
    }
    int l = 1,r = n;
    ll ans = 0;
    while (1)
    {
        if (l == r) break;
        ll t = min(a[l],a[r]);
        if (c[l] != c[r])
        {
            ans += t;
        }
        if (a[l] == t)
        {
            l++;
            a[r] -= t;
        }
        else
        {
            r--;
            a[l] -= t;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
