#include<bits/stdc++.h>
using namespace std;
int a[200010];int n,m;
int f(int x,bool z,int cnt,int s)
{
    int ss=s;
    if(z==1) ss&=a[x];

    if(x<n)
        return max(f((x+1),1,cnt+1,ss),f(x+1,0,cnt,ss));
    else
    {
        if(cnt==m)
            return ss;
        else
            return 0;
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    if(m==1)
    {
        int ans=-1000;
        for(int i=1;i<=n;i++)
        {
            ans=max(ans,a[i]);
        }
        cout<<ans;
    }
    else if(m==n)
    {
        int ans=a[1];
        for(int i=1;i<=n;i++)
        {
            ans&=a[i];
        }
        cout<<ans;
    }
    else if(m==2)
    {
        int ans=-1000;
        for(int i=1;i<n;i++)
            for(int j=i+1;j<=n;j++)
                ans=max(ans,a[i]&a[j]);
        cout<<ans;
    }
    else
        cout<<max(f(1,1,1,a[1]),f(1,0,0,a[1]));
    return 0;
}
