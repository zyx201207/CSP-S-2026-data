#include<bits/stdc++.h>
using namespace std;
long long maxx1,n,m,a[200005],maxx2;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    maxx1=a[n];
    for(int i=1;i<m;i++)
    {
        maxx1&=a[n-i];
    }
    maxx2=a[n-1];
    for(int i=1;i<m;i++)
    {
        maxx2&=a[n-i-1];
    }
    cout<<max(maxx1,maxx2);
    return 0;
}
