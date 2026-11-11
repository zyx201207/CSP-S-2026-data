#include <bits/stdc++.h>
using namespace std;

string c[200005];
int a[200005];
long long sa[200005];
map<char, int> mp, mp1, mp2;

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    cin >> n;
    long long ans = 0, sum = 0;
    string s;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> c[i];
        for (int j = 1; j <= a[i]; j++)
        {
            s += c[i];
        }
        sum += a[i];
    }
    long long l = 0, r = sum - 1;
    while (l <= r)
    {
        if (s[l] != s[r])
        {
            ans++;
        }
        l++;
        r--;
    }
    cout << ans;
    return 0;
}
