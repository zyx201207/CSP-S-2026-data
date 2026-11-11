#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],b[200005],mx,v[200005];
void dfs(int i)
{
    if(i>m)
    {
        int num=b[1];
        for(int j=2;j<=m;j++)num=num&b[j];
        mx=max(mx,num);
        return;
    }
    for(int j=1;j<=n;j++)
    {
        if(v[j]==0)b[i]=a[j];
        v[j]=1;
        dfs(i+1);
        v[j]=0;
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    dfs(1);
    cout<<mx;
}
