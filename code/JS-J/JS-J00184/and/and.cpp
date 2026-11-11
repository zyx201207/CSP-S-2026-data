#include <bits/stdc++.h>
using namespace std;
long long a[200005],cnt[200005];
bool cmp(unsigned long long x,unsigned long long y)
{
    return x > y;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    unsigned long long n,m,mul;
    cin >> n >> m;
    for(unsigned long long i = 1;i <= n;i++) scanf("%lld",&a[i]);
    sort(a + 1,a + n + 1,cmp);
    for(unsigned long long i = 1;i < m;i++)
    {
        if(i == 1) mul = a[i] & a[i + 1];
        mul &= a[i + 1];
    }
    cout << mul;
    return 0;
}
