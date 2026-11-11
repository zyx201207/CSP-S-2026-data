#include<bits/stdc++.h>
using namespace std;
int n,m,a[200011],maxl=0,ans=0;
int andd(int x,int y)
{
    int b[51],c[51],i=0,j=0,fh=0,d;
    while(x>0)
    {
        i++;
        b[i]=x%2;
        x=x/2;
    }
    while(y>0)
    {
        j++;
       c[j]=y%2;
        y=y/2;
    }
    i=min(i,j);
    d=i;
    while(i>0)
    {
        if(b[i]==1&&c[i]==1)
        {
            b[i]=1;
        }
        else
        {
            b[i]=0;
        }
        i--;
    }
    j=1;
    for(int s=1;s<=d;s++)
    {
        fh+=j*b[s];
        j=j*2;
    }
    return fh;
}
void dfs(int x,int flag,int jishu)
{
    if(flag==m)
    {
        ans=max(ans,jishu);
        return;
    }
    for(int i=x+1;i<=n;i++)
    {
        if(flag==0)
        {
            dfs(i,1,a[i]);
        }
        else
        {
            dfs(i,flag+1,andd(a[i],jishu));
        }
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
        maxl=max(maxl,a[i]);
    }
    if(m==1)
    {
        cout<<maxl;
        return 0;
    }
    if(m==n)
    {
        ans=a[1];
        for(int i=2;i<n;i++)
        {
            ans=andd(ans,a[i]);
        }
        cout<<ans;
        return 0;
    }
    dfs(0,0,0);
    cout<<ans;
    return 0;
}
