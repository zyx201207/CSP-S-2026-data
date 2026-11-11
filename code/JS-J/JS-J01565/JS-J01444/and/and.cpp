#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=2e5+3;
int n,m;
int ans=0;
int ma=0;
int a[MAXN];
void dfs(int i,int j,int x)
{
    if(j==m)
    {
        ans=max(ans,x);
        return;
    }
    if(i>n)return;
    dfs(i+1,j+1,x&a[i]);
    dfs(i+1,j,x);
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        ma=max(a[i],ma);
    }
    if(m==1)
    {
        cout<<ma;
        return 0;
    }
    if(n<=20)
    {
        dfs(1,0,4294967295);
    }
    cout<<ans;
    return 0;
}
