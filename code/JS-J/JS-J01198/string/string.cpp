#include <bits/stdc++.h>
using namespace std;
long long n,a[200010],ans=0;
char c[200010];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
    }
    long long l=1,r=n,i=1,li=0,lr=0;
    while(l<r)
    {
        if(c[l]!=c[r])
        {
            if(a[l]-li<a[r]-lr)
            {
                ans+=a[l]-li;
                lr+=a[l]-li;
                li=0;
                l++;
            }
            if(a[l]-li>a[r]-lr)
            {
                ans+=a[r]-lr;
                li+=a[r]-lr;
                lr=0;
                r--;
            }
            if(a[l]-li==a[r]-lr)
            {
                ans+=a[r]-lr;
                l++;
                r--;
                li=0;
                lr=0;
            }
        }
        else
        {

            if(a[l]-li<a[r]-lr)
            {
                lr+=a[l]-li;
                l++;
                li=0;
            }
            if(a[l]-li>a[r]-lr)
            {
                li+=a[r]-lr;
                r--;
                lr=0;
            }
            if(a[l]-li==a[r]-lr)
            {
                l++;
                r--;
                li=0;
                lr=0;
            }
        }
    }
    cout<<ans;
    return 0;
}
