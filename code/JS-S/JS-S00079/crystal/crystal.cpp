#include <bits/stdc++.h>
using namespace std;
long long a[500005];
long long cha[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin >> n >> m;
    long long cnt = 0;
    long long maxn = -10000001;
    long long minn = 10000001;
    for(long long i = 1; i <= n ; i++)
    {
        cin >> a[i];
        maxn = max(a[i],maxn);
        minn = min(a[i],minn);
        if(a[i] == i) cnt++;
    }
    if(cnt == n)
    {
        long long  jsq = 1;
        long long ans = 1;
        while(m - jsq >= 0 && jsq < a[n])
        {
            m -= jsq;
            jsq++;
            ans++;
        }
        cout << ans;
        return 0;
    }
    if(n * m > 5000000000)
    {
        long long k = (maxn - minn) / (n - 1);
        long long  jsq = 1;
        long long ans = 1;
        while(m - (jsq * k)>= 0 && jsq * k <= maxn - minn)
        {
            m -= (jsq * k);
            jsq++;
            ans++;
        }
        cout << ans;
        return 0;
    }
    long long nowans = 0;
    for(long long k = minn; k <= maxn; k++)
    {
        int mt = m;
        long long ans = 0;
        long long b[500005];
        for(long long i = 1; i <= n; i++)
        {
            b[i] = k - a[i];
        }
       
        sort(b + 1,b + n + 1);
         
        for(long long i = 1; i <= n ; i++)
        {
            if(b[i] >= 0)
            {
                if(mt - b[i] >= 0)
                {
                     mt -= b[i];
                    ans++;
                }
            }
        }
        nowans = max(ans,nowans);
    }
    cout << nowans;
    return 0;
}