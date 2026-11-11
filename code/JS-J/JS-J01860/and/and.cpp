#include <bits/stdc++.h>
using namespace std;

const long long N = 2e5+5;
long long m,n;
long long maxa=-1;
long long a[N];
long long ans;
long long find2_biggest(long long a[])
{
    long long maxn = -1;
    long long fx,fy;//mark
    for(long long i = 1;i <= n/2;i++)
    {
        for(long long j = i+1;(j<=n)&&(j!=i);j++)
        {
            if(a[i] >= 0 && a[j] >= 0)
            {
                if(a[i] & a[j] > maxn)
                {
                    maxn = a[i] & a[j];
                    fx = i;
                    fy = j;
                }
            }
        }
    }
    a[fx] = -1;
    a[fy] = -1;
    return maxn;
}
long long find_biggest(long long a[],long long ans)
{
    long long maxn = -1;
    long long flag;//mark
    for(long long i = 1;i <= n;i++)
    {
        if(a[i] > 0)
        {
            if(a[i] & ans > maxn)
            {
                maxn = a[i]&ans;
                flag = i;
            }
        }
    }
    a[flag] = -1;
    return maxn;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(long long i = 1;i <= n;i++)
    {
        cin >> a[i];
        maxa = max(maxa,a[i]);
    }
    if(m == 1)
    {
        cout << maxa;
        return 0;
    }
    if(m == n)
    {
        ans = a[1];
        for(long long i = 2;i <= n;i++)
        {
            ans &= a[i];
        }
        cout << ans;
        return 0;
    }
    ans = find2_biggest(a);
    while(m>2)
    {
        ans = find_biggest(a,ans);
        m--;
    }
    cout << ans;
    return 0;
}
