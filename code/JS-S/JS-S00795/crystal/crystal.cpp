#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
int a[N];
int num,sum,ans;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= n;i++)
        cin >> a[i];
    sort(a + 1,a + 1 + n);
    num = n / 2 + n % 2;
    for (int i = 1;i <= num;i++)
        sum += abs (a[i] - a[num]);
    for (int i = num;i <= n;i++)
        a[i] = a[num];
    for (int i = 1;i <= n;i++)
        if (a[i] == a[num])
            ans++;
    cout << ans;
    return 0;
}
