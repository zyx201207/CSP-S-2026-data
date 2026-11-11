#include <bits/stdc++.h>
using namespace std;
int a[200001];
char c[200001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    int p = n,q = 0;
    long long s = 0,f = 0,sum = 0;
    for (int i = 1;i<=n;i++)
    {
        cin >> a[i] >> c[i];
        s += a[i];
    }
    s /= 2;
    for (int i = 1;i<=n;i++)
    {
        if (f+a[i] <= s)
        {
            f += a[i];
            while (1)
            {
                if (a[p]-q <=a[i])
                {
                    if (c[p] != c[i])
                    {
                        sum += a[p]-q;
                    }
                    a[i] -= a[p]-q;
                    q = 0;
                }
                else
                {
                    if (c[p] != c[i])
                    {
                        sum += a[i];
                    }
                    q += a[i];
                    a[i] = 0;
                    break;
                }
                p--;
            }
            if (f == s)
            {
                break;
            }
        }
        else
        {
            int t = s-f;
            while (1)
            {
                if (a[p]-q <=t)
                {
                    if (c[p] != c[i])
                    {
                        sum += a[p]-q;
                    }
                    t -= a[p]-q;
                    q = 0;
                }
                else
                {
                    if (c[p] != c[i])
                    {
                        sum += t;
                    }
                    q += t;
                    t = 0;
                    break;
                }
                p--;
            }
            break;
        }
    }
    cout << sum;
    return 0;
}
