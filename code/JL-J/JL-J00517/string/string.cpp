#include<bits/stdc++.h>
using namespace std;
long long l,r,n;
long long ans;
long long a[200100];
char c[200100];
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>c[i];
    }
    l=0;
    r=n-1;
    for(int i=1;i<=n;i++)
    {
        if(c[l]!=c[r])
        {
            ans+=min(a[l],a[r]);
            if(a[l]>a[r])
            {
                a[l]=a[l]-a[r];
                a[r]=0;
                r--;
            }
            else
            if(a[l]<a[r])
            {
                a[r]=a[r]-a[l];
                a[l]=0;
                l++;
            }
            else
            if(a[l]==a[r])
            {
                a[l]=0;
                a[r]=0;
                r--;
                l++;
            }
        }
        else
        if(c[l]==c[r])
        {
            r--;
            l++;
        }
        if(l>=r)
            break;

    }
    cout<<ans;

    return 0;
}
