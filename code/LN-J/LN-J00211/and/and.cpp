#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m,ans;
int l[300005];
bool v[300005];

void dfs(int i,int j,int s)
{
    if(i==n&&j==m)
    {
        ans=max(ans,s);
        return ;
    }
    if(j>m)return ;
    dfs(i+1,j+1,s&l[i+1]);
    dfs(i+1,j,s);
}

signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    scanf("%lld %lld",&n,&m);
    for(int i=1;i<=n;i++)cin >>l[i];
    dfs(1,1,l[1]);
    dfs(2,1,l[1]);
    
    cout <<ans;
}