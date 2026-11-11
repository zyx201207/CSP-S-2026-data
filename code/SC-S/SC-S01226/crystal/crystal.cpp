#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
const long long N = 5e3 + 5;
long long n,m,a[N],sa[N];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++) scanf("%lld",&a[i]);
    bool flag1 = true, flag2 = true;
    for(int i = 2 ; i <= n ; i++)
    {
        if(a[i] != a[i-1]) flag1 = false;
    }
    if(flag1)
    {
        cout << n << '\n';
        return 0;
    }
    sort(a + 1, a + n + 1);
    int d = a[2] - a[1];
    for(int i = 3 ; i <= n ; i++)
    {
        if(a[i] - a[i-1] != d) flag2 = false;
    }
    if(flag2)
    {
        long long num = m / d;
        long long sum = 0;
        for(int i = 1 ; i < n ; i++)
        {
            sum += i;
            if(sum > num)
            {
                cout << i;
                return 0;
            }
        }
        cout << n;
        return 0;
    }
    for(int i = 1 ; i <= n ; i++) sa[i] = sa[i-1] + a[i];
    long long ans = 0;
    long long l = 1, r = 1;
    while(true)
    {
        long long len = r - l + 1;
        long long sum = a[r] * len - (sa[r] - sa[l-1]);
        if(sum <= m)
        {
            ans = max(ans, len);
            if(r < n)
            {
                r++;
                continue;
            }
            else break;
        }
        else
        {
            l++;
            continue;
        }
    }
    cout << ans << '\n';
    return 0;
}
