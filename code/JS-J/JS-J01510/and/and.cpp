#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int x=n-m;
    long long ans=a[n];
    for(int i=n-1;i>x;i--)
    {
        ans&=a[i];
    }
    cout<<ans;
    return 0;
}
