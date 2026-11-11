#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],sum[200005],ans;
char c[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        sum[i]=sum[i-1]+a[i];
    }
    long long s;
    if(sum[n]%2==0)
        s=sum[n]/2;
    else
        s=sum[n]/2+1;
    long long mid;
    for(int i=1;i<=n;i++)
        if(sum[i]>=s)
        {
            mid=i;
            break;
        }
    int mo=n,nowl=0,l=1,nowm=0;
    while(l<mid&&mo>mid)
    {
        if(c[l]!=c[mo])
        {
            if((a[l]-nowl)>a[mo]-nowm)
            {
                ans+=a[mo]-nowm;
                nowl+=a[mo]-nowm;
                mo--;
                nowm=0;
            }
            if((a[l]-nowl)==a[mo]-nowm)
            {
                ans+=a[mo]-nowm;
                l++;
                mo--;
                nowl=0,nowm=0;
            }
            if((a[l]-nowl)<a[mo]-nowm)
            {
                nowm+=a[l]-nowl;
                ans+=(a[l]-nowl);
                nowl=0;
                l++;
            }
        }
        else
        {
            if((a[l]-nowl)>a[mo]-nowm)
            {
                nowl+=a[mo]-nowm;
                mo--;
                nowm=0;
            }
            if((a[l]-nowl)==a[mo]-nowm)
            {
                l++;
                mo--;
                nowl=0,nowm=0;
            }
            if((a[l]-nowl)<a[mo]-nowm)
            {
                nowm+=a[l]-nowl;
                nowl=0;
                l++;
            }
        }

    }
    if(l==mid&&mo==mid+1&&sum[n]%2==0)
    {
        cout<<ans+a[l];
        return 0;
    }
    if(n<=5)
    {

        cout<<ans;
        return 0;
    }
    if(l==mid)
    {
        for(int i=l+1;i<mo;i++)
            if(c[i]!=c[l])
            ans+=a[i];
        ans-=nowl;
    }
    else
    {
        for(int i=mo-1;i>l;i--)
            if(c[i]!=c[mo])
            ans+=a[i];
        ans-=nowm;
    }
    cout<<ans;
}
