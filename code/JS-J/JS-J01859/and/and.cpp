#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
string s[1000005];
long long ans = INT_MIN;
string f(int a)
{
    string s;
    while(a)
    {
        if(a % 2 == 0)
            s += '0';
        else
            s += '1';
        a /= 2;
    }
    return s;
}
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s[i] = f(a[i]);

    }
    sort(a + 1, a + n + 1);
    if(m == 1)
    {
        cout << a[n];
    }
    else if(m == 2)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = i + 1; j <= n; j++)
            {
                ans = max(a[i] & a[j], ans);
            }
        }
        cout << ans;
    }
    else if(m == n - 1)
    {
        for(int i = 1; i <= n; i++)
        {
            long long cnt = a[i];
            for(int j = 1; j <= n; j++)
            {
                if(j == i)
                    continue;
                cnt &= a[j];
            }
            ans = max(ans, cnt);
        }
        cout << ans;
    }
    else if(m == n)
    {
        for(int i = 2; i <= n; i++)
        {
            a[1] &= a[i];
        }
        cout << a[1];
    }
    else
    {
        sort(a + 1, a + n + 1, greater<int>());
        cout << a[m];
    }
    return 0;
}
