#include <iostream>
#include <algorithm>
using namespace std;
long long n,m,a[500005],b[500005],ans = 0;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++)
        cin >> a[i];
    sort(a + 1,a + n + 1);
    long long num = 0;
    for (long long i = 2;i <= n;i++)
    {
        b[i] = a[i] - a[i - 1];
        if (b[i] == 0)
            num++;
        else
        {
            ans = max(num,ans);
            num = 0;
        }
    }
    if (num == n - 1)
    {
        cout << n;
        return 0;
    }
    num = 0;
    for (long long i =1;i <= n;i++)
    {
        long long s = 0;
        num = 1;
        for (long long j = i - 1;j >= 1;j--)
        {
            if (s + a[i] - a[j] > m)
                break;
            s += a[i] - a[j];
            num++;
        }
        ans = max(ans,num);
    }
    cout << ans;
    return 0;
}
