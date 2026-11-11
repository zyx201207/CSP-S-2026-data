#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
    return x>y;
}
int n,m,a[2005],vis[2005],sum=0x3f3f3f3f;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=m;i++)
    {
        sum&=a[i];
    }
    cout<<sum;
    return 0;
}
