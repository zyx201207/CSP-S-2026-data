#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200010],q[200010];
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    cout<<a[n-2];
    return 0;
}
