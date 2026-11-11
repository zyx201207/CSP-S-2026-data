#include <bits/stdc++.h>
using namespace std;

long long a[200001];
long long s[200001];

bool cmp(long long a, long long b)
{
    return a > b;
}
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1, cmp);
    s[1] = a[1];
    for (int i = 2; i <= n; i++)
    {
        s[i] = s[i - 1] & a[i];
    }
    cout << s[m] << endl;
    return 0;
}
