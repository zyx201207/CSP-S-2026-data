#include <bits/stdc++.h>
using namespace std;
int a[500002]={0}, f[500002]={0};
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    long long m;
    cin >> n >> m;
    for (int i=1; i<=n; i++)
    {
        cin >> a[i];
    }
    sort(a, a+n);
    for (int i=1; i<=n; i++)
    {
        f[i] = f[i-1] + a[i];
    }
    int ans = 0;
    int l = 1, r = 2;
    while(r <= n)
    {
        if(l == r)
        {
            r++;
            continue;
        }
        long long needed_op = (r-l+1) * a[r] - (f[r] - f[l-1]);
        if(needed_op > m)
        {
            l++;
        }
        else
        {
            ans = max(ans, r-l+1);
            r++;
        }
    }
    cout << ans << endl;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
