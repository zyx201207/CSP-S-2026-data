#include<bits/stdc++.h>
using namespace std;
const int N =5e5+10;
long long n,m;
long long a[N],ans,ans2;
bool A = 1,B = 1;
bool check(int k)
{
    long long mn = 1e18,lc = 1,rc =k;
    while(rc<= n)
    {
        int bz = a[rc];
        ans = 0;
        for(int i = rc-1;i>=lc;i--)
        {
            ans +=bz-a[i];
        }
        mn = min(ans,mn);
        lc++,rc++;
    }
    return mn<= m;

}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i = 1; i<= n;i++)cin >> a[i];
    long long d= a[2] - a[1];
    if(d != 1)A = 0;
    for(int i = 3; i<= n;i++)
    {
        if(a[i]-a[i-1] != d)B= 0;
    }
    sort(a+1,a+n+1);
    if(A)
    {
        int l = 1,r = n;
        while(l<=r)
        {
           int mid = (l+r)/2;
           if(mid*(mid+1)/2<=m)
           {
               l = mid+1;
               ans2 = mid+1;
           }
           else r = mid-1;
        }
        cout << ans2;
    }
    else if(B)
    {
        int l = 1,r = n;
        while(l<=r)
        {
           int mid = (l+r)/2;
           if(mid*(mid+1)*d/2<=m)
           {
               l = mid+1;
               ans2 = mid+1;
           }
           else r = mid-1;
        }
        cout << ans2;
    }
    else
    {
        int l = 1,r = n;
        while(l<=r)
        {
           int mid = (l+r)/2;
           if(check(mid))
           {
               l = mid+1;
               ans2 = mid;
           }
           else r = mid-1;
        }
    cout << ans2;
    }
    return 0;
}
