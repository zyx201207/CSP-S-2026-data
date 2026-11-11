#include <bits/stdc++.h>
using namespace std;
int n;
long long a[200005],sum[200005],c;
char b[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    sum[0] = 0;
    for(int i = 1;i <= n;i++)
    {
        cin a[i] >> b[i];
        sum[i] = sum[i - 1]+a[i];
        c = max(a[i],c);
    }
    cout << c;
    return 0;
}
