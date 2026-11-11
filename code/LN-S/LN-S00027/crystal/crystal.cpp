#include <bits/stdc++.h>
using namespace std;
long long a[500001];
long long c[500001];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,max = 0 ;
    cin >> n >> m;
    a[0] = 0;
    c[0] = 0;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        c[i] = c[i-1] + a[i];
    }
    sort(a + 1,a + n + 1);
    for(int i = 0;i <= n;i++)
    {
        for(int j = i+1;j <= n;j++)
        {
            if(c[j] - c[i] + m >= (j - i) * a[j] && j - i > max)
            {
                max = j - i;
            }
        }
    }

    cout << max;


return 0;
}
