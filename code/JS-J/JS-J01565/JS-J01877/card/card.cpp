#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],ans[300005],p[300005];
int t[500005],f[300005],d[300005],g[300005],b[300005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    int flag=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        p[a[i]]=i;
    }
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>a[i+1]&&i!=n)
        {
            flag=0;
        }
        if(a[i]!=a[i+1]&&a[i]!=n)
        {
            sum++;
        }
    }
    if(m==1)
    {
        cout<<n<<'\n';
    }
    if(m<=2)
    {
        for(int i=1;i<=n;i++)
        {
            if(a[n]==1&&a[i]==1)
            {
                ans[1]++;
            }
            if(a[n]==0&&a[i]==0)
            {
                ans[0]++;
            }
            if(a[n]==1&&a[i]==0||a[n]==0&&a[i]==1)
            {
                ans[0]++;
                ans[1]++;
            }
        }
        for(int i=1;i<=m;i++)
        {
            cout<<ans[i]<<" ";
        }
        return 0;
    }
    if(flag==1)
    {
        for(int i=1;i<=n;i++)
        {
            if(a[i]<a[i+1]||i==n)
            {
                ans[a[i]]=i;
            }
        }
        for(int i=1;i<=m;i++)
        {
            cout<<ans[i]<<" ";
        }
        return 0;
    }
    if(n<=500&&m<=300)
    {
        for(int i=1;i<=n;i++)
        {
            memset(t,0,sizeof(t));
            memset(f,0,sizeof(f));
            memset(d,0,sizeof(d));
            int l=0;
            for(int j=i;j<=n;j++)
            {
                if(f[a[j]]==1)
                {
                    for(int k=d[a[j]]+1;k<=l;k++)
                    {
                        f[t[k]]=0;
                        d[t[k]]=0;
                        t[k]=0;
                    }
                    l=d[a[j]];
                }
                else
                {
                    f[a[j]]=1;
                    l++;
                    t[l]=a[j];
                    d[a[j]]=l;
                }

            }
            for(int j=1;j<=l;j++)
            {
                ans[t[j]]++;
            }
        }
        for(int i=1;i<=m;i++)
        {
            cout<<ans[i]<<" ";
        }
        return 0;
    }
    if(sum<=4999)
    {
        int sum=1,x=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==a[i+1])
            {
                sum++;
            }
            else if(a[i]!=a[i+1]||i==n)
            {
                g[a[i]]+=sum-1;
                x++;
                b[x]=a[i];
                sum=1;
            }
        }
        for(int i=1;i<=x;i++)
        {
            memset(t,0,sizeof(t));
            memset(f,0,sizeof(f));
            memset(d,0,sizeof(d));
            int l=0;
            for(int j=i;j<=x;j++)
            {
                if(f[b[j]]==1)
                {
                    for(int k=d[b[j]]+1;k<=l;k++)
                    {
                        f[t[k]]=0;
                        d[t[k]]=0;
                        t[k]=0;
                    }
                    l=d[b[j]];
                }
                else
                {
                    f[a[j]]=1;
                    l++;
                    t[l]=b[j];
                    d[b[j]]=l;
                }

            }
            for(int j=1;j<=l;j++)
            {
                ans[t[j]]++;
            }
        }
        for(int i=1;i<=m;i++)
        {
            cout<<ans[i]+g[i]<<" ";
        }
        return 0;
    }
    return 0;
}
