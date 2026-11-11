#include <bits/stdc++.h>
using namespace std;
int n, a[500007], sum = 0, sun = 0;
long long m;
int main()
{
    freopen ("crystal.in","r",stdin);
    freopen ("crystal.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    sum /= n;
    for (int i = 1;i <=n;i++)
    {
        if (a[i] > sum)
        {
            sun += 0;
        }
        else if(a[i] == sum)
        {
            sun++;
        }
        else if(a[i] < sum)
        {
            for (int j = 1;j <= 1e8;j++)
            {
                if (m <= 0)
                {
                    if (a[i] == sum)
                    {
                        sun++;
                    }
                    break;
                }
                else if (a[i] < sum)
                {
                    a[i]++;
                    m -= 1;
                }
                if (a[i] == sum)
                {
                    sun++;
                    break;
                }
            }
        }
    }
    cout << sun;
    return 0;
}
