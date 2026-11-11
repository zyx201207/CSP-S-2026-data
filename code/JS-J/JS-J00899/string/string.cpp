#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n;
int a[N];
char c[N];

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> c[i];
    }
    int l = 1, r = n;
    long long ans = 0;
    while (l < r)
    {
        int num = min(a[l], a[r]);
        a[l] -= num, a[r] -= num;
        if (c[l] != c[r]) ans += num;
        if (a[l] == 0) l++;
        if (a[r] == 0) r--;
    }
    cout << ans;
    return 0;
}
