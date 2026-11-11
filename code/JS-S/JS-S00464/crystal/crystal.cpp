#include<bits/stdc++.h>
using namespace std;

long long n,m,ss,mx=1,a[500005];
bool flag = true;
bool f = true;

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i=1 ; i<=n ; i++)
    {
        cin >> a[i];
        if(a[i] != i)
            flag = false;
        if(i>2 && a[i]-a[i-1]!=a[i-1]-a[i-2])
            f = false;
    }
    if(n == 1)
    {
        cout << 1;
        return 0;
    }
    if(flag)
    {
        long long lft=1,rgt=n-1;
        while(lft < rgt)
        {
            long long mid = (lft+rgt+1)/2;
            if((mid+(long long)1)*mid/2 <= m)
                lft = mid;
            else
                rgt = mid-1;
        }
        if((lft+1)*lft/2 <= m)
            cout << lft+1;
        else
            cout << 1;
        return 0;
    }
    if(f)
    {
        long long r = a[2]-a[1];
        long long lft=1,rgt=n-1;
        while(lft < rgt)
        {
            long long mid = (lft+rgt+1)/2;
            if((mid+(long long)1)*mid/2*r <= m)
                lft = mid;
            else
                rgt = mid-1;
        }
        if((lft+1)*lft/2*r <= m)
            cout << lft+1;
        else
            cout << 1;
        return 0;
    }
    sort(a+1,a+n+1);
    if(n <= 5005)
    {
        for(int i=2 ; i<=n ; i++)
        {
            long long x = m;
            long long sum = 1;
            for(int j=i-1 ; j>=1 ; j--)
            {
                if(x >= a[i]-a[j])
                {
                    sum++;
                    x -= a[i]-a[j];
                }
                else
                    break;
            }
            mx = max(mx,sum);
        }
        cout << mx;
        return 0;
    }
    for(long long i=2 ; i<=n ; i++)
        ss += (a[i]-a[i-1])*(i-1);
    long long u=2,v=n,h=n;
    while(ss > m)
    {
        h--;
        if(a[u]-a[u-1] > (v-u+1)*(a[v]-a[v-1]))
        {
            ss -= a[u]-a[u-1];
            u++;
        }
        else
        {
            ss -= (v-u+1)*(a[v]-a[v-1]);
            v--;
        }
    }
    if(ss <= m)
        cout << h;
    else
        cout << 1;
    return 0;
}
