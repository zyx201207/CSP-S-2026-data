#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,i,j;
    cin>>n>>m;
    int lst[m+1];
    memset(lst,-1,sizeof(lst));
    int a[n+2];
    a[n+1]=0;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        lst[a[i]]=i;
    }
    bool t[m+5][m+5];
    int h[m+1];
    memset(t,0,sizeof(t));
    memset(h,0,sizeof(h));
    for(i=1;i<=m;i++)
    {
        int p=lst[i];
        if(p==-1) continue;
        for(j=1;j<=m;j++)
        {
            t[i][j]=t[a[p+1]][j];
        }
        t[i][i]=1;
    }
    for(i=n;i>=1;i--)
    {
        h[a[i]]++;
    }
    int ans[m+1];
    memset(ans,0,sizeof(ans));
    for(i=1;i<=m;i++)
    {
        if(h[i]==0) continue;
        for(j=1;j<=m;j++)
        {
            ans[j]+=t[i][j]*h[i];
        }
    }
    for(i=1;i<=m;i++) cout<<ans[i]<<" ";
    return 0;
}
