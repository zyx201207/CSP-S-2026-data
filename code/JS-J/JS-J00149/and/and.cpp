#include<iostream>
using namespace std;
int n,m;
int a[200005];
//int dp[10005][10005];
int maxx=-1;
int dfs(int deep,int num,int ans)
{
    ans=ans&a[num];
    if(deep==m)
    {
        maxx=max(ans,maxx);
        return ans;
    }
    for(int i=num+1;i<=n;i++)
    {
        dfs(deep+1,i,ans);
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
    bool flag=true;
    int kskbl=1;
    for(int i=1;i<=20;i++)
    {
        if(n==kskbl)
            break;
        if(i==20)
            flag=false;
        kskbl*=2;
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=i-1)
            flag=false;
    }
    if(flag)
    {
        cout<<n-m;
        return 0;
    }
    /*dp[1][0]=0;
    dp[1][1]=a[1];
    for(int i=1;i<=m;i++)
    {
        for(int j=2;j<=n;j++)
        {
            int c=dp[i-1][j-1]&a[j];
            dp[i][j]=max(dp[i][j-1],c);
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<dp[m][n];*/
    for(int i=1;i<=n-m+1;i++)
    {
        dfs(1,i,a[i]);
    }
    cout<<maxx;
    return 0;
}
