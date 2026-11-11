#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200010];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    if(m==1)
    {
        int maxa=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            maxa=max(maxa,a[i]);
        }
        cout<<maxa<<endl;
    }
    else if(m==2)
    {
        int maxa=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        for(int i=1;i<=n-1;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                maxa=max(maxa,a[i]&a[j]);
            }
        }
        cout<<maxa<<endl;
    }
    else if(m==3)
    {
        int maxa=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        for(int i=1;i<=n-2;i++)
        {
            for(int j=i+1;j<=n-1;j++)
            {
                for(int k=j+1;k<=n;k++)
                {
                    maxa=max(maxa,a[i]&a[j]&a[k]);
                }
            }
        }
        cout<<maxa<<endl;
    }
    else if(m==4)
    {
        int maxa=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        for(int i=1;i<=n-3;i++)
        {
            for(int j=i+1;j<=n-2;j++)
            {
                for(int k=j+1;k<=n-1;k++)
                {
                    for(int l=k+1;l<=n;l++)
                    {
                        maxa=max(maxa,a[i]&a[j]&a[k]&a[l]);
                    }
                }
            }
        }
        cout<<maxa<<endl;
    }
    else if(m==n)
    {
        int ans;
        cin>>a[1];
        ans=a[1];
        for(int i=2;i<=n;i++)
        {
            cin>>a[i];
            ans&=a[i];
        }
        cout<<ans<<endl;
    }
    else
    {
        int anss=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            anss=max(anss,a[i]);
        }
        cout<<anss<<endl;
    }
    return 0;
}
