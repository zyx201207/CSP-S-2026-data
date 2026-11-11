#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int n, a[500010], b[500010], d[500010], c;
    long long m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    for(int i = 0; i < n; i++)
    {
        for(int j = n - 1 - i; j > 0; j--)
        {
            if(a[j - 1] == a[j])
            {
                b[j - 1] = b[j];
            }
            else
            {
                b[j - 1] = a[n - i - 1] - a[j - 1];
            }
        }
        sort(b, b + n);
        c = m;
        for(int k = 0; k < n - 1 - i; k++)
        {
            if(c >= b[k])
            {
                c -= b[k];
                d[n - 1 - i]++;
            }
            else
            {
                break;
            }
        }
    }
    sort(d, d + n);
    cout << d[n - 1] + 1;
    return 0;
}
