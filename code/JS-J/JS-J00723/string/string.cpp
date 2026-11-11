#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    char st[200005];
    int s[200005], a[200005];
    char ch[200005];
    a[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> s[i] >> ch[i];
        a[i] = a[i - 1] + s[i];
        for(int j = a[i - 1] + 1; j <= a[i]; j++)
        {
            st[j] = ch[i];
        }
    }
    int ans = 0;
    if(a[n] % 2)
    {
        for(int i = 1; i <= (a[n] - 1) / 2; i++)
        {
            if(st[i] != st[(a[n] + 1 - i)])
                ans++;
        }
    }
    else
    {
        for(int i = 1; i <= a[n] / 2; i++)
        {
            if(st[i] != st[(a[n] + 1 - i)])
                ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
