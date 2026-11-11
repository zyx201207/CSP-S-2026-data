#include<bits/stdc++.h>
using namespace std;
int a[200010];
int res[200010];
int n,m;
int maxn=0;
void dfs(int now,int cnt,int ans,int flag)
{
    if(now==n+1)
    {
        if(cnt==m)
        {
            maxn=max(maxn,ans);
        }
        return;
    }
    res[now]=1;
    if(flag==0)
    {
        dfs(now+1,cnt+1,a[now],1);
    }
    else
    {
        dfs(now+1,cnt+1,ans&a[now],1);
    }
    res[now]=0;
    dfs(now+1,cnt,ans,flag);
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    int mx=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        mx=max(mx,a[i]);
    }
    if(m==1)
    {
        cout<<mx<<"\n";
        return 0;
    }
    if(m==2)
    {
        int aa=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i!=j)
                {
                    aa=max(aa,(a[i]&a[j]));
                }
            }
        }
        cout<<aa<<"\n";
        return 0;
    }
    if(m==n)
    {
        int aa=a[1];
        for(int i=2;i<=n;i++)
        {
            aa=aa&a[i];
        }
        cout<<aa<<"\n";
        return 0;
    }
    dfs(1,0,0,0);
    cout<<maxn<<"\n";
    return 0;
}
