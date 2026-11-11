#include<bits/stdc++.h>
using namespace std;
int a[200001];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    int t=a[n];
    for(int i=n;i>=n-m+1;i--)
        t=t&a[i];
    cout<<t;
    return 0;
}
