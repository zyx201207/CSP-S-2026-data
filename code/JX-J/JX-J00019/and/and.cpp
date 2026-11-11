#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 5;
const int MAXM = 2e5 + 5;

int n, m;

ll a[MAXN];

vector<string> arr;

string str_bld;
void init_2(ll x)
{
    if (x == 0)
    {
        return;
    }
    if (x == 1)
    {
        str_bld += '1';
        return;
    }
    init_2(x / 2);
    str_bld += (char)('0' + x % 2);
}

ll convert(string x)
{
    string tmp = x;
    ll k = 1;
    ll sum = 0;
    for (int i = tmp.size() - 1; i >= 0; --i)
    {
        sum += (long long)(tmp[i] - '0') * (long long)k;
        k <<= 1;
    }
    return sum;
}

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        str_bld = "";
        init_2(a[i]);
        arr.push_back(str_bld);
    }

    sort(arr.begin(), arr.end());

    if (m == 1)
    {
        cout << convert(arr[arr.size() - 1]);
        return 0;
    }
    else if (m == 2)
    {
        ll ans = 0;
        for (int i = 1; i <= n - 1; ++i)
        {
            for (int j = i + 1; j <= n; ++j)
            {
                ans = max(ans, a[i] & a[j]);
            }
        }
        cout << ans;
        return 0;
    }
    else if (m == n)
    {
        ll ans = a[1];
        for (int i = 2; i <= n; ++i)
        {
            ans = ans & a[i];
        }
        cout << ans;
        return 0;
    }

    int idx = arr.size() - 1;
    ll ans = convert(arr[idx]);
    m--;
    idx--;
    while (m--)
    {
        ll num = convert(arr[idx]);
        ans = ans & num;
        idx--;
        if (ans == 0)
        {
            break;
        }
    }
    cout << ans;

    return 0;
}
