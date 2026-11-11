#include<bits/stdc++.h>
using namespace std;
long long a[214748],dp[214748];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=n;j>=i;j--)
        {
            dp[j]=max(a[i]&dp[j-1],dp[j]);
        }
    }
    cout<<a[n];
    return 0;
}
