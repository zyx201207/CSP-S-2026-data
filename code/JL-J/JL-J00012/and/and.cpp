#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
int n,m,a[MAXN],ans;
void dfs(int i,int from,int x)
{
    if(i==m)
    {
        ans=max(ans,x);
        return;
    }
    if(from+i>n)
        return;
    for(int j=from;j<=n;j++)
        dfs(i+1,j,x&a[j]);
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n-m;i++)
        dfs(1,i,a[i]);
    cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
