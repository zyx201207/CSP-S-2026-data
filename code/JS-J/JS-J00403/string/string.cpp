#include<bits/stdc++.h>
using namespace std;

int n,a[200005];
char c[200005];
long long ans=0;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
    }
    int l=1,r=n;
    while(l<=r)
    {
        int cnt;
        if(a[l]<a[r])
        {
            a[r]-=a[l];
            if(c[l]!=c[r])
            {
                ans+=a[l];
            }
            a[l]=0;
            l++;
        }
        if(a[l]>a[r])
        {
            a[l]-=a[r];
            if(c[l]!=c[r])
            {
                ans+=a[r];
            }
            a[r]=0;
            r--;
        }
        if(a[l]==a[r])
        {
            if(c[l]!=c[r])
            {
                ans+=a[l];
            }
            a[l]=0;
            a[r]=0;
            l++;
            r--;
        }
    }
    cout<<ans;
    return 0;
}
