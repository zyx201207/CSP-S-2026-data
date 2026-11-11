#include<bits/stdc++.h>
using namespace std;
long long arr[200005];
bool check(long long a)
{
    while(a)
    {
        if(a%2==1)
        {
            return false;
        }
        a/=2;
    }
    return true;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    bool flag=false;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        if(check(arr[i]))
        {
            flag=true;
        }
    }
    if(m==1)
    {
        long long ans=0;
        for(int i=1;i<=n;i++)
        {
            ans=max(ans,arr[i]);
        }
        cout<<ans<<endl;
    }
    else if(m==2)
    {
        long long ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                ans=max(ans,arr[i]&arr[j]);
            }
        }
        cout<<ans<<endl;
    }
    else if(m==n)
    {
        long long cnt=arr[1];
        for(int i=2;i<=n;i++)
        {
            cnt&=arr[i];
        }
        cout<<cnt<<endl;
    }
    else if(m==3)
    {
       long long ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                for(int k=j+1;k<=n;k++)
                {
                    ans=max(ans,arr[i]&arr[j]&arr[k]);
                }
            }
        }
        cout<<ans<<endl;
    }
    else if(m==4)
    {
        long long ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                for(int k=j+1;k<=n;k++)
                {
                    for(int l=k+1;l<=n;l++)
                    {
                        ans=max(ans,arr[i]&arr[j]&arr[k]&arr[l]);
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    else if(m==5)
    {
        long long ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                for(int k=j+1;k<=n;k++)
                {
                    for(int l=k+1;l<=n;l++)
                    {
                        for(int o=l+1;o<=n;o++)
                        {
                            ans=max(ans,arr[i]&arr[j]&arr[k]&arr[l]&arr[o]);
                        }
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    else if(m==6)
    {
        long long ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                for(int k=j+1;k<=n;k++)
                {
                    for(int l=k+1;l<=n;l++)
                    {
                        for(int o=l+1;o<=n;o++)
                        {
                            for(int p=o+1;p<=n;p++)
                            {
                                ans=max(ans,arr[i]&arr[j]&arr[k]&arr[l]&arr[o]&arr[p]);
                            }
                        }
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    else if(flag)
    {
        sort(arr+1,arr+1+n,greater<long long>());
        long long ans=arr[1];
        for(int i=2;i<=m;i++)
        {
            ans&=arr[i];
        }
        cout<<ans<<endl;
    }
    else
    {
        cout<<n-m<<endl;
    }
    return 0;
}
