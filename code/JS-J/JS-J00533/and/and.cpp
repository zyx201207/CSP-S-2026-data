#include<bits/stdc++.h>
using namespace std;
int m,n,a[200005],l,ans;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    l=a[1];
    for(int i=2;i<=n;i++)
    {
        cin>>a[i];
        l=l&a[i];
    }
    sort(a+1,a+n+1);
    if(m==1)
    {
        cout<<a[n];
        return 0;
    }
    if(m==0)
    {
        cout<<l;
        return 0;
    }
    for(int i=1;i<=m;i++)
    {
        ans=ans&a[n-i+1];
    }
    cout<<ans;
    return 0;
}
