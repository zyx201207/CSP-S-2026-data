#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans=-1;
void dfs(int i,int fa,int sum)
{
    if(i==m+1)
    {
        ans=max(ans,sum);
        return;
    }
    if(n-fa+i<m)return;
    for(int j=fa+1;j<=n;j++)
    {
        dfs(i+1,j,sum&a[j]);
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
    dfs(1,0,((long long)(1)>>31)-1);
    cout<<ans;
    return 0;
}
