#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
long long a[N], s[N], m;
int n;

bool isvail(int len)
{
    for(int l = 1; l + len - 1 <= n; l++)
    {
        int r = l + len - 1;
        long long sum = a[r] * len - (s[r] - s[l - 1]);
        if(sum <= m) return true;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
    int l = 0, r = n;
    while(l < r)
    {
        int mid = (l + r + 1) >> 1;
        if(isvail(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l << '\n';
    return 0;
}