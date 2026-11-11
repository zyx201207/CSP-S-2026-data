#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    int a[200005]={};
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    int x=a[n];
    for(int i=n-1;i>=n-m+1;i--)x&=a[i];
    cout<<x<<'\n';
    return 0;
}
