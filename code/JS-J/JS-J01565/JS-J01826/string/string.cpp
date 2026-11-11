#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],x,ans,z,y;
char s1[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=0;i<n;i++)
    {
        cin>>a[i];
        x=x+a[i];
        cin>>s1[i];
    }
    z=0,y=n-1;
    while(z<y)
    {
        if(s1[z]!=s1[y])
        {
            ans+=min(a[z],a[y]);
        }

        if(a[z]>a[y])
        {
            a[z]=a[z]-a[y];
            a[y]=0;
            y=y-1;
        }
        else if(a[z]<a[y])
        {
            a[y]=a[y]-a[z];
            a[z]=0;
            z=z+1;
        }
        else
        {
            a[y]=0,a[z]=0;
            y=y-1;
            z=z+1;
        }
    }
    cout<<ans;
    return 0;
}
