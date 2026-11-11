#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N],dp[N][N],b[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=b[i-1]+a[i];
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            dp[i][j]=max(dp[i][j-1],dp[i-1][j]+)
        }
    }
    return 0;
}
