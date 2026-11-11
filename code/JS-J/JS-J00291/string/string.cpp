#include<bits/stdc++.h>
using namespace std;
long long n,a[200011],ans=0,he=0,r,f;
char c[200011];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        he+=a[i];
    }
    r=n;
    f=1;
    he=he/2;
    while(he>0)
    {
        if(a[f]>a[r])
        {
            if(c[f]!=c[r])
            {
                ans+=a[r];
            }
            a[f]=a[f]-a[r];
            he=he-a[r];
            r--;
        }
        else if(a[f]<a[r])
        {
            if(c[f]!=c[r])
            {
                ans+=a[f];
            }
            a[r]=a[r]-a[f];
            he=he-a[f];
            f++;
        }
        else
        {
            if(c[f]!=c[r])
            {
                ans+=a[f];
            }
            he=he-a[f];
            f++;
            r--;
        }
    }
    cout<<ans;
    return 0;
}
