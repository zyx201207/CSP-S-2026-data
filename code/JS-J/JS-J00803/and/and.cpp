#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","r",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    int ans=a[n]&a[n-1];
    for(int i=1;i<=m-2;i++)
    {
        ans=ans&a[i];
    }
    cout<<ans;
}
