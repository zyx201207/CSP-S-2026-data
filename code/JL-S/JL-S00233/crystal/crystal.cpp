#include<bits/stdc++.h>
using namespace std;
const int N = 500010;
long long a[N];
int s[10100];
long long n,m;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> n >> m;
    long long t = m;
    for(int i = 1;i <= n;i ++)
    {
        cin >> a[i];
    }
    sort(a+1,a+1+n);
    int l = 1,r = n;

    for(int x = 0;x < 5000;x ++)
    {
        m = t;
        if(n/2+1+x > n) break;
        s[x+1] = 1;
        for(int i = n/2+x;i >= 1;i --)
        {
            if(a[n/2+1+x] - a[i] <= m)
            {
                m -= (a[n/2+1+x] - a[i]);
                s[x+1] ++;
            }
        }
    }
    for(int x = 0;x < 5000;x ++)
    {
        m = t;
        if(n/2-x < 1) break;
        s[x+1+5000] = 1;
        for(int i = n/2-x-1;i >= 1;i --)
        {
            if(a[n/2-x] - a[i] <= m)
            {
                m -= (a[n/2+x] - a[i]);
                s[x+1+5000] ++;
            }
            else break;
        }
    }
    int ans = 0;
    for(int i = 1;i <= 10000;i ++)
    {
        ans = max(s[i],ans);
    }
    cout << ans;
    return 0;
}
