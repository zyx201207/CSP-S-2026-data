#include<bits/stdc++.h>
using namespace std;
string s;
char c[200010];
int a[200010];
long long j,n,b,d,e,f,g,h,l,k,ans,i,n1,n2;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        cin>>c[i];
        ans+=a[i];
    }

    if(n%2)
    {
        ans=ans/2;
         for(i=1;i<=(n-1)/2;i++)
        {
        j=n+1-i;
        if(c[i]!=c[j])
        {

            if(a[i]<a[j])
                a[i+1]+=abs(a[i]-a[j]);
            else
            a[j-1]+=abs(a[i]-a[j]);
        }
        else
        {
            ans=ans-min(a[i],a[j]);
            if(a[i]<a[j])
                a[i+1]+=abs(a[i]-a[j]);
            else
            a[j-1]+=abs(a[i]-a[j]);
        }
        }
            //ans-=a[n/2+1]/2;
    }
    else
    {
        ans=ans/2;
         for(i=1;i<=n/2;i++)
        {
        j=n+1-i;
        if(c[i]!=c[j])
        {

            if(a[i]<a[j])
                a[i+1]+=abs(a[i]-a[j]);
            else
            a[j-1]+=abs(a[i]-a[j]);
        }
        else
        {
            ans-=min(a[i],a[j]);
            if(a[i]<a[j])
                a[i+1]+=abs(a[i]-a[j]);
            else
            a[j-1]+=abs(a[i]-a[j]);

        }
    }
    }
    cout<<ans;
    return 0;
}
