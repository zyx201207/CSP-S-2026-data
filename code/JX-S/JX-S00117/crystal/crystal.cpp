#include <bits/stdc++.h>
using namespace std;
long long n,m,a[1000010],s[1000010];
bool check(long long k)
{
    for(long long i = 1;i + k - 1 <= n;i++)
        if(s[i + k - 1] - s[i - 1] + m >= a[i + k - 1] * k)
            return 1;
    return 0;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i <= n;i++) cin>>a[i];
    sort(a + 1,a + n + 1);
    for(int i = 1;i <= n;i++) s[i] = s[i - 1] + a[i];
    long long l = 1,r = n;
    while(l <= r)
    {
        long long mid = (l + r) / 2;
        if(check(mid)) l = mid + 1;
        else r = mid - 1;
    }
    cout<<l - 1<<endl;
    return 0;
}
