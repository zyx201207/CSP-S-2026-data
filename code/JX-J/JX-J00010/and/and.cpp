#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
bool vis[N];
int n,m,a[N],ans=-1;
void task1()
{
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,a[i]);
    }
    cout<<ans;
}
void task2()
{
    ans=a[1];
    for(int i=2;i<=n;i++)
    {
        ans=ans&a[i];
    }
    cout<<ans;
}
int dfs(int x)
{
    int maxn=0;
    if(x==m+1)
    {
        ans=max(ans,maxn);
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        //int ansn=a[i];
        if(vis[i]==0)
        {
            if(a[i]==0)
            {
            maxn=a[i];
            }
            maxn=maxn&a[i];
            vis[i]=1;
            maxn=dfs(x+1);
            vis[i]=0;
        }
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    if(m==1){
        task1();
    }
    else if(n==m)
    {
        task2();
    }
    else
    {
        dfs(1);
        cout<<ans;
    }
}
