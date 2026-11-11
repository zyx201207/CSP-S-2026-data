#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    long long q=a[n];
    int ans=0;
    for (int i=n-1;ans<=m;i--)
    {
        q=q&a[i];
        ans++;
    }
    cout<<q;
    return 0;
}
