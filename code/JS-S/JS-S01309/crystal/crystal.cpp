#include<bits/stdc++.h>
using namespace std;
long long n,m,ans2,ans3=0,ans=-1,y;
long long a[500005],b[500005],c[500005];
int flag=0;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(long long i=2;i<=n;i++)
    {
        b[i-1]=a[i]-a[i-1];
        if(b[i-1]!=1)
            flag=1;
    }
    if(flag==0)
    {
        long long ans1=0,f=0;
        for(int i=1;i<=m;i++)
        {
            f+=i;
            if(f>m)
            {
                ans1=i;
                break;
            }
        }
        cout<<ans1;
        return 0;
    }
    for(long long i=n;i>=1;i--)
    {
        long long j=i-1;
        ans2=1;
        y=m;
        for(long long k=1;k<=n;k++)
            c[k]=a[k];
        while(c[i]-c[j]<=y and j>0)
        {
            y=y-(c[i]-c[j]);
            c[j]=c[i];
            j--;
        }
        for(long long k=1;k<n;k++)
        {
            ans3=1;
            while(c[k]==c[k+1])
            {
                ans3=ans3+1;
                k++;
            }
            ans2=max(ans2,ans3);
        }
        ans=max(ans,ans2);
        if(i<=ans)
            break;
    }
    cout<<ans;
    return 0;
}
