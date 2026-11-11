#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
bool cmp(long long x,long long y)
{
    return x>=y;
}
int main()
{
    freopen("add.in","r",stdin);
    freopen("add.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    int ans=a[1];
    for(int i=2;i<=m;i++)
    {
        ans=ans&a[i];
    }
    cout<<ans;
    return 0;
}
