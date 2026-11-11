#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string,out", "w", stdout);
    int n;
    cin >> n;
    int a[1000000005]
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[n];
    }
    for(i = a[1]; i <= a[n]; i++)
    {
        for(j = a[n]; j >= a[1]; j--)
        {
            if(a[i] != a[j])
            {
                ans += 1;
            }
        }
    }
    cout << ans;
    return 0;
}
