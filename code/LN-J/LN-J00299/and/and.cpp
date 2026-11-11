#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    long long a[n+5];
    long long maxn=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        maxn=max(maxn,a[i]);
    }
    sort(a+1,a+1+n);
    if(m==1)
    {
        cout<<a[n];
        return 0;

    }
    if(m==n)
    {
        long long ans=a[1];
        for(int i=2;i<=n;i++)ans=ans&a[i];
        cout<<ans;
        return 0;
    }
    if(m==2)
    {
        long long ans=0;
        for(int i=1;i<n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans;
        return 0;
    }
    if(maxn<=4)
    {
        int q=0,w=0,e=0,r=0,t=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==4)q++;
            if(a[i]==3)w++;
            if(a[i]==2)e++;
            if(a[i]==1)r++;
            if(a[i]==0)t++;
        }
        if(m<=q)
        {
            cout<<4;
            return 0;
        }
        else if(w+e>=m){
            cout<<2;
            return 0;

        }
        else if(w+r>=m){
            cout<<1;
            return 0;

        }
        else cout<<0;
        return 0;
    }
    if(m==n-1)
    {
        long long ans=0;

        for(int i=1;i<=n;i++)
        {
            long long sum=0;
            if(i==1)
            {
                sum=a[2];
            }
            else{
                sum=a[1];
            }
            for(int j=2;j<=n;j++)
            {
                if(i==j)continue;
                sum=sum&a[j];
            }
            ans=max(ans,sum);
        }
        cout<<ans;
        return 0;
    }
    long long ans=a[n];
    for(int i=1;i<m;i++)
    {
        ans=ans&a[n-i];
    }
    cout<<ans;
    return 0;
}
