#include<iostream>
#include<cmath>
using namespace std;

int n,m;
int a[200010];
int ans=0;

void dfs(int l,int s,int zhi)
{
    if(l==n&&s<m)
        return;
    if(s==m)
    {
        ans=max(ans,zhi);
        return;
    }
    for(int i=l+1;i<=n;i++)
        dfs(i,s+1,zhi&a[i]);
}

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    dfs(0,0,pow(2,31)-1);
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
