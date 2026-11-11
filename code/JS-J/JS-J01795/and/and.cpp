#include<bits/stdc++.h>
using namespace std;

long long a[200005];

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= n;i ++)
    {
        cin >> a[i];
    }
    long long maxn = 0;
    for (int i = 1;i <= n;i ++)
    {

        for (int j = 1;j <= n;j ++)
        {
            if (i != j)
            {
                maxn = max(maxn,a[i] & a[j]);
            }
        }
    }
    cout << maxn;
    return 0;
}
