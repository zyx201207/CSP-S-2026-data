#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],p[200010];
long long ans;
bool vis[200010],b;
void print()
{
    long long x=p[1];
    for(long long i=2;i<=m;i++)
        x=p[i]&x;
    ans=max(ans,x);
}
void dfs(long long i)
{
    if(i==m+1)
    {print();return;}
    for(long long j=1;j<=n;j++)
    {
        if(vis[j]==0&&a[j]>=p[i-1])
        {
            vis[j]=1;
            p[i]=a[j];
            dfs(i+1);
            vis[j]=0;
        }
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    if(a[1]==0) {cout<<0;b=1;}
    if(b==0&&m>2&&m!=n)
        dfs(1);
    if(b==0&&m==n)
    {
        ans=a[1];
        for(long long i=2;i<=n;i++)
            ans=a[i]&ans;
    }
    if(b==0&&m==1)
    {
        for(long long i=1;i<=n;i++)
            ans=max(ans,a[i]);
    }
    if(b==0&&m==2)
    {
        for(long long i=1;i<=n;i++)
            for(long long j=i+1;j<=n;j++)
            ans=max(ans,a[i]&a[j]);
    }
    cout<<ans;
    fclose(stdin);fclose(stdout);
    return 0;
}
