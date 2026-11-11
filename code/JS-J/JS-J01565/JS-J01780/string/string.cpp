#include <bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
    }
    long long ans=0,l=1,r=n;
    while(l<r)
    {
        if(a[l]>a[r])
        {
            if(c[l]!=c[r])
            {
                ans+=a[r];
                a[l] = a[l]-a[r];
                r--;
            }
            else
            {
                a[l] = a[l]-a[r];
                r--;
            }
        }
        if(a[l]==a[r])
        {
            if(c[l]!=c[r])
            {
                ans+=a[r];
                l++;
                r--;
            }
            else
            {
                l++;
                r--;
            }
        }
        if(a[l]<a[r])
        {
            if(c[l]!=c[r])
            {
                ans+=a[l];
                a[r] = a[r]-a[l];
                l++;
            }
            else
            {
                a[r] = a[r]-a[l];
                l++;
            }
        }
    }
    cout<<ans;
    return 0;
}
