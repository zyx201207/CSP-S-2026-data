#include <bits/stdc++.h>
using namespace std;
using LL=long long;
LL n,m,ans=1;
LL a[200005];
int main()
{
    freopen("and,in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++)  cin>>a[i];
    cout<<n-m;
    return 0;
}
