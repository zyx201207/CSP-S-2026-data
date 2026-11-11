#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n, m, cnt = 1, l = 0;
    cin >> n >> m;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort (a + 1, a + n + 1);
    for (int i = n; i > 0; i--)
    {
        int m2 = m;
        for (int j = i - 1; j > 0; j--)
        {
            if (a[j] < a[i])
            {
                m2 = m2 + a[j] - a[i];
            }
            cnt++;
            if (m2 <= 0)
            {
                break;
            }
        }
        if (cnt > l)
        {
            l = cnt;
        }
        cnt = 1;
    }
    cout << l;

    return 0;
}
