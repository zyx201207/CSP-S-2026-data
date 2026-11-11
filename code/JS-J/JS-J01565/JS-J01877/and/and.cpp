#include<bits/stdc++.h>
using namespace std;
int n,m,ans=0;
int a[200005],vis[200005];
void dfs(int p,int sum,int num,int f)
{
    if(num==m)
    {
        ans=max(sum,ans);
        return;
    }
    if((m-num)<(n-p+1)) dfs(p+1,sum,num,f);
    if(f==0) dfs(p+1,a[p],num+1,1);
    else dfs(p+1,sum & a[p],num+1,1);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int f=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]>=4) f=0;
    }
    if(n<=20)
    {
        dfs(1,0,0,0);
        cout<<ans;
        return 0;
    }
    if(m==1)
    {
        int zd=0;
        for(int i=1;i<=n;i++)
        {
            zd=max(zd,a[i]);
        }
        cout<<zd;
        return 0;
    }
    if(m==n)
    {
        int sum=a[1];
        for(int i=2;i<=n;i++)
        {
            sum=sum & a[i];
        }
        cout<<sum;
        return 0;
    }
    if(m==2&&n<=2000)
    {
        int zd=0;
        for(int i=1;i<n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                int s=a[i] & a[j];
                zd=max(zd,s);
            }
        }
        cout<<zd;
        return 0;
    }
    if(f==1)
    {
        int a0=0,a1=0,a2=0,a3=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==0) a0++;
            else if(a[i]==1) a1++;
            else if(a[i]==2) a2++;
            else if(a[i]==3) a3++;
        }
        if(m<=a3+a2)
        {
            cout<<2;
        }
        else
        {
            if(m<=a3+a1)
            {
                cout<<1;
            }
            else
            {
                cout<<0;
            }
        }
        return 0;
    }
    return 0;
}
