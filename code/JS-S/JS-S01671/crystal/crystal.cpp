#include <bits/stdc++.h>
#define long long int
using namespace std;

int a[500005];

signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int bigans = 1;
    for(int i = n; i >= 1; i--)
    {
        int ans = 1;
        int sum = 0;
        for(int j = i - 1; j >= 1; j--)
        {
            if(a[i] - a[1] >= m)break;
            sum += a[i] - a[j];
            if(sum > m)
            {
                break;
            }
            else
            {
                ans++;
            }
        }
        bigans = max(bigans, ans);
    }
    cout << bigans;
    return 0;
}
