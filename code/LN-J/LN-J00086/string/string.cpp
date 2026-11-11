#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,sum;
int a[200005];
char c[200005];
int l,r;
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
    }
    l=1,r=n;
    while(l<r)
    {
        if(a[l]==a[r])
        {
            l++;
            r--;
            if(c[l]!=c[r])
            {
                sum+=a[l];
            }
        }
        else if(a[l]<=a[r])
        {
            a[r]-=a[l];
            if(c[l]!=c[r])
            {
                sum+=a[l];
            }
            l++;
        }
        else
        {
            a[l]-=a[r];
            if(c[l]!=c[r])
            {
                sum+=a[r];
            }
            r--;
        }
    }
    cout<<sum;
    return 0;
}
