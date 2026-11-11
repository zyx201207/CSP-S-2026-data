#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
string s;
ll ans;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for (int i = 1;i <= n;i++)
    {
        ll x;
        char c;
        cin >> x >> c;
        while (x--)
            s += c;
    }
    ll l = (ll)s.size();
    for (int i = 0;i < l/2;i++)
        if (s[i] != s[l-i-1])
            ans++;
    cout << ans;
    return 0;
}
