#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005];
int main()
{
    freopen("and3.in","r",stdin);
    freopen("and3.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    cout<<a[n-m+1]<<'\n'<<a[n];
    return 0;
}
