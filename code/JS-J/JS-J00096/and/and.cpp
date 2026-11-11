#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],an;
void dfs(int x,int y,int sum)
{
    if (x==n && y==m)
    {
        an=max(an,sum);
        return;
    }
    if (n-x>m-y)
    {
        dfs(x+1,y,sum);
    }
    if (y<m)
    {
        dfs(x+1,y+1,sum&a[x+1]);
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    dfs(0,0,pow(2,31)-1);
    cout<<an;
    return 0;
}
