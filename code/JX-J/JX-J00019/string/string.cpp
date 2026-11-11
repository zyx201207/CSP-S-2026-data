#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 5;
const int MAXA = 1e9 + 5;
int n;
ll a[MAXN];
vector<char> chr;
string str = "";
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    chr.push_back('0');

    for (int i = 1; i <= n; ++i)
    {
        char c;
        cin >> a[i] >> c;
        chr.push_back(c);
        string tmp(a[i], c);
        str += tmp;
    }

    ll ans = 0;
    ll l = 0, r = str.size() - 1;
    while (l < r)
    {
        if (str[l] != str[r])
        {
            ans++;
        }
        l++;
        r--;
    }

    cout << ans;

    return 0;
}
