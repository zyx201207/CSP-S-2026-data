#include<bits/stdc++.h>
using namespace std;
int n , tans;
long long s[500010] , u[500010] , d[500010]  ,t[500010];
long long sum = 0 , m ;
long long a[500010];
bool check(int mid , int now)
{
    long long ss = s[now+mid-1] - s[now-1] - mid * (t[n]-t[n-now+1]);
    if(ss > m ) return false;
    return true;
}
int main()
{
    freopen("crystal.in" , "r" , stdin);
    freopen("crystal.out" , "w" , stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i++ )
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    int cnt = 0;
    for (int i = 2 ; i <= n ; i++ )
    {
        t[i] = t[i-1] + a[i] - a[i-1];
    }
    for(int i = n-1 ; i >= 1 ; i--)
    {
        u[i] = u[i+1] + a[i+1] - a[i];
        cnt++;
        d[cnt] = u[i];
        s[cnt] = s[cnt-1] + d[cnt];
    }
    for (int i = 1 ; i < n ; i++ )
    {
        int k = n-i;
        int l = 0 , r = k , ans;
        while(l <= r)
        {
            int len = (l + r) >> 1;
            if (check(len,i))
            {
                l = len + 1;
                ans = len;
            }
            else
            {
                r = len - 1;
            }
        }
        tans = max(tans , ans+1);
    }
    cout << tans << endl;
    return 0;
}
