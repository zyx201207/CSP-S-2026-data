#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
int a[N];
int n, m;

bool cmd(int x, int y)
{
    return x > y;
}

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n, cmd);
    for(int i = 0; i < m; i++)
    {
        a[0] &= a[i];
    }
    if(a[0] == 0)
    {
        cout << 1 << '\n';
        return 0;
    }
    cout << a[0] << '\n';
    return 0;
}
