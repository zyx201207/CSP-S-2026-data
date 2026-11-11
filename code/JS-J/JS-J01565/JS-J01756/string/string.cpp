#include <bits/stdc++.h>
using namespace std;

struct T
{
    long long p;
    char k;
};

T a[200001];

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].p >> a[i].k;
    }
    long long ans = 0;
    for (int i = 1, j = n; i < j; )
    {
        if (a[i].k == a[j].k)
        {
            if (a[i].p < a[j].p)
            {
                i++;
            }
            else if (a[i].p > a[j].p)
            {
                j--;
            }
            else
            {
                i++;
                j--;
            }
        }
        else
        {
            if (a[i].p < a[j].p)
            {
                ans += a[i].p;
                a[j].p -= a[i].p;
                i++;
            }
            else if(a[i].p == a[j].p)
            {
                ans += a[i].p;
                i++;
                j--;
            }
            else if (a[i].p > a[j].p)
            {
                ans += a[j].p;
                a[i].p -= a[j].p;
                j--;
            }
        }
    }
    cout << ans << endl;
    return 0;
}

