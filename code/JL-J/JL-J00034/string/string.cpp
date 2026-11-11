#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans;
char x[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>x[i];
        if(x[i]==x[i-1])
        {
            a[i-1]+=a[i];
            a[i]==0;
        }
    }
    if(n%2)
    {
        long long cnt=0,ans1=0,ans2=0,anss;
        int mid=(n-1)/2+1;
        char midx;
        for(long long i=1;i<=n;i++)
        {
            if(cnt<mid&&a[i]!=0)
            {
                cnt+=a[i];
            }
            else
            {
                midx=x[i];
                anss=i;
                break;
            }
        }
        for(long long i=1;i<=anss;i++)
        {
            if(a[i]!=0&&x[i]!=midx)
            {
                ans1=ans1+a[i];

            }
        }
        for(long long i=anss;i<=n;i++)
        {
            if(a[i]!=0&&x[i]!=midx)
            {
                ans2=ans2+a[i];

            }
        }
        ans=min(ans1,ans2);
    }
    else
    {
        long long cnt=0,ans1=0,ans2=0,anss;
        int mid=n/2+1;
        char midx;
        for(long long i=1;i<=n;i++)
        {
            if(cnt<mid&&a[i]!=0)
            {
                cnt+=a[i];
            }
            else
            {
                midx=x[i];
                anss=i;
                break;
            }
        }
        for(long long i=1;i<=anss;i++)
        {
            if(a[i]!=0&&x[i]!=midx)
            {
                ans1=ans1+a[i];

            }
        }
        for(long long i=anss;i<=n;i++)
        {
            if(a[i]!=0&&x[i]!=midx)
            {
                ans2=ans2+a[i];

            }
        }
        ans=min(ans1,ans2);
    }
    cout<<ans;














    return 0;
}
