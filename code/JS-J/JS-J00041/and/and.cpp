#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M = 2e5 + 10;
int a[M];
int n,m;
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for(int i = 0;i < n;i++)
    {
        cin>>a[i];
    }
    sort(a,a + n);
    int ans = a[n - 1];
    for(int i = n - 2;i >= n - m;i--)
    {
        ans &= a[i];
    }
    cout<<ans;
    return 0;
}