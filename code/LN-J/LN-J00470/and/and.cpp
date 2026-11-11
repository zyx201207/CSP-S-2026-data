#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200009];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int ans=a[n];
    for(int i=2;i<=m;i++)
    {
        ans=ans&a[n-i];
    }
    cout<<ans;
    return 0;
}
