#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],maxx;
void dfs(int x,long long ans,int sum)
{
    if(sum>m)return ;
    if(x==n+1)
    {
        if(m!=sum)return ;
        maxx=max(maxx,ans);
        return ;
    }
    dfs(x+1,ans&a[x],sum+1);
    dfs(x+1,ans,sum);
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
    if(n<=20)
    {
        dfs(1,(1<<30)-1,0);
        cout<<maxx;
        return 0;
    }
    if(m==1)
    {
        for(int i=1;i<=n;i++)
        {
            maxx=max(maxx,a[i]);
        }
        cout<<maxx;
        return 0;
    }
    if(n==m)
    {
        maxx=(1<<30)-1;
        for(int i=1;i<=n;i++)
        {
            maxx&=a[i];
        }
        cout<<maxx;
        return 0;
    }
    if(n<=2000&&m==2)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                maxx=max(maxx,a[i]&a[j]);
            }
        }
        cout<<maxx;
        return 0;
    }
    cout<<0;
    //rp++;
    return 0;
}
