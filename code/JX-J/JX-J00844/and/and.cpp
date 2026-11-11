#include<bits/stdc++.h>
using namespace std;
int a[200001],n,m,ans;
void dfs(int d,int k,int s)
{
    if(d>n)return;
    if(k>=m)
    {
        ans=max(ans,s);
        return;
    }
    dfs(d+1,k+1,s&a[d]);
    dfs(d+1,k,s);
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1,greater<int>());
    dfs(1,0,-1);
    cout<<ans;
return 0;
}
/*++rp*/
