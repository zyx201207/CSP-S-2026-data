#include <bits/stdc++.h>
using namespace std;
freopen("crystal.in", "r", stdin);
freopen("crystal.out", "w", stdout);
int main()
{
    int n,m;
    cin >> n >> m;
    int a[i],a[j];
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(a[i]=a[j])
            {
                ans++;
                j++;
            }
        }
    }
    cout << n;
    return 0;
}
