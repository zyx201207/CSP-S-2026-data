#include<bits/stdc++.h>

using namespace std;

int n, m;
long long a[500010];
long long s[500010];
int ans;

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);

    for(int i = 1; i <= n; i++)
    {
        s[i] = a[n] - a[i];
    }

    long long sum = 0;
    for(int r = n, l = n; r >= 1 && r >= l; r--)
    {
        while(l > 1 && sum <= m)
        {
            ans = max(ans, r - l + 1);
            l--;
            sum += s[l] - s[r];
        }    
        if(sum <= m)
        {
            ans = max(ans, r - l + 1);
        }
        sum -= (r - l) * (s[r - 1] - s[r]);
    }

    cout << ans << endl;
    return 0;
}