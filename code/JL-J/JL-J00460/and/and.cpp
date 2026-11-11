#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],mm=0,ans=0,f[200010];
void dfs(int cnt,int sum)
{
    if(cnt>m)
    {
        if(sum>ans) ans=sum;
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        if(f[i]==0)
        {
            f[i]=1;
            dfs(cnt+1,sum&a[i]);
            f[i]=0;
        }

    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]>mm) mm=a[i];
    }
    int an=a[1];
    for(int i=2;i<=n;i++) an=an&a[i];
    if(m==1)
    {
        cout<<mm;
        return 0;
    }
    if(m==n)
    {
        cout<<an;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        f[i]=1;
        dfs(2,a[i]);
        f[i]=0;
    }
    cout<<ans;
    return 0;
}
