#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
    ll x;
    char s;
};
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;
    string S;
    vector<node> a(n + 1);
    ll ans = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].x >> a[i].s;
        ans += a[i].x;
        ll xo = a[i].x;
        while(xo--)
        {
            S += a[i].s;
        }
    }
    //cout << S << endl;
    ans /= 2;

    string S2;
    ll be = 0;
    if(ans % 2 == 0)
    {
        be = ans;
    }
    else be = ans + 1;

    for(int i = be + 1 ; i < S.size(); i++)
    {
        S2 += S[i];
    }
    reverse(S2.begin(), S2.end());
    //cout << S2 << endl;
    ll cnt  = 0;
    for(int i = 0; i < S2.size(); i++)
    {
        if(S2[i] != S[i])
        {
            cnt++;
        }
    }
    cout << cnt << "\n";

    //reverse(a.begin(), a.end());
    //cout << fixed << setprecision(n) << ans << endl;

    return 0;
}
