#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],i,j,m,ans;
bool cmp(int x,int y)
{
    return x>=y;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n,cmp);
    ans=a[1];
    for(i=2;i<=m;i++)
    {
        ans=ans&a[i];
    }
    cout<<ans;
    return 0;
}
