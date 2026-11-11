#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long sum[500005];
long long ans=0;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    // for(int i=1;i<=n;i++)
    // {
    //     cout<<a[i]<<' ';
    // }
    for(int i=1;i<=n-1;i++)
    {
        sum[i]=a[i+1]-a[i];
    }
    // for(int i=1;i<=n;i++)
    // {
    //     cout<<sum[i]<<' ';
    // }
    long long l=1,r=1,t=0,len=0;
    bool flag=0;
    sum[n]=LLONG_MAX;
    while(r<=n)
    {
        r++,len++;
        // t+=2*t+sum[r-1];
        t+=len*(a[r]-a[r-1]);
        //cout<<sum[r-1]<<' ';
        //cout<<r-1<<' ';
        //cout<<t<<' ';
        if(t>m&&!flag&&sum[r]==0)
        {
            flag=1;
            ans=max(ans,len);
            //cout<<ans<<'\n';
        }
        if(t>m&&(sum[r]!=0))
        {
            //ans=max(ans,r-l);
            while(t>m)
            {
                //cout<<"f"<<' '<<m<<'\n';
                l++,len--;
                t-=(a[r]-a[l-1]);
                //cout<<t<<' ';
                // if(r>n-1)
                // {
                //     break;
                // }
            }
            len=abs(len);
            flag=0;
            // if(l>r)
            // {
            //     swap(l,r);
            // }
            ans=max(ans,len+1);
            //cout<<ans<<'\n';
        }
        if(t==m&&sum[r]!=0)
        {
            ans=max(ans,len+1);
            //cout<<l<<' '<<r<<' '<<ans<<'\n';
            l++,len--;
            t-=(a[r]-a[l-1]);
            //cout<<ans<<'\n';
        }
    }
    if(!ans)
    {
        cout<<m<<'\n';
        return 0;
    }
    cout<<ans<<'\n';
    return 0;
}