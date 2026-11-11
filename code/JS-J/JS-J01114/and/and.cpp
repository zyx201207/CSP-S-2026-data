#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1;
long long n,m,ans,a[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(long long i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    ans=a[n];
    for(long long i=1; i<m; i++)
    {
        ans&=a[n-i];
    }
    cout<<ans;
    return 0;
}


