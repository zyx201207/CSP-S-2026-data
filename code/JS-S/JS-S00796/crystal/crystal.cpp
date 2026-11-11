#include <iostream>
#include <algorithm>
using namespace std;
long long a[500005],s[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    long long m;
    cin >> n >> m;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    sort(a + 1,a + n + 1);
    for (int i = 1;i <= n;i++)
    {
        s[i] = a[i] - a[i - 1];
    }
    long long maxn = 1;
    for (int i = 1;i <= n;i++)
    {
        long long j = 1;
        long long sum = 0,tmp = m;
        while (tmp - sum - s[i-j] >= 0 && i > j)
        {
            tmp -= sum;
            tmp -= s[i-j];
            sum += s[i-j];
            j++;
        }
        maxn = max(maxn,j);
    }
    cout << maxn << endl;
    return 0;
}
