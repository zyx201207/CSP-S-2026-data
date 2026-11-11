#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
struct S
{
    int g;
    long long l , r;
    char c;
}a[N];
int main()
{
    freopen("string5.in" , "r" , stdin);
    freopen("string.out" , "w" , stdout);
    int n;
    cin >> n;
    long long s = 0;
    for (int i = 1; i <= n; i++)
    {
        int d;
        cin >> d >> a[i].c;
        a[i].l = s;
        a[i].r = s + d - 1;
        s += d;
        a[i].g = d;
    }
    int pos1 = 1 , pos2 = n;
    long long ans = 0;
    while (pos1 < pos2)
    {
        if (a[pos1].c != a[pos2].c)
        {
            if (a[pos1].g < a[pos2].g)
            {
                ans += a[pos1].g;
                a[pos2].r -= a[pos1].g;
                a[pos2].g -= a[pos1].g;
                pos1++;
            }
            else
            {
                ans += a[pos2].g;
                a[pos1].l += a[pos2].g;
                a[pos1].g -= a[pos2].g;
                pos2--;
            }
        }
        else
        {
            if (a[pos1].g < a[pos2].g)
            {
                a[pos2].r -= a[pos1].g;
                a[pos2].g -= a[pos1].g;
                pos1++;
            }
            else
            {
                a[pos1].l += a[pos2].g;
                a[pos1].g -= a[pos2].g;
                pos2--;
            }
        }
        //cout << ans << "\n";
    }
    cout << ans;
    return 0;
}
