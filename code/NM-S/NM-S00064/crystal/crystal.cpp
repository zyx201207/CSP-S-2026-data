#include<bits/stdc++.h>
using namespace std;
long long n,m,l=0;
long long a[10000056];
long long c[10000056];
long long dp[1000026];
long long maxn=0,ans=0;
long long s[10006000];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(n<=5000)sort(a+1,a+n+1);
    dp[1]=0;
    for(int i=2;i<=n;i++)
    {
        dp[i]=(a[i]-a[i-1])*(i-1)+dp[i-1];
    }
    for(int i=1;i<=n;i++)
    {
        if(dp[i]<=m)
        {
            maxn=i;
        }
    }
    cout<<maxn;
    return 0;
}
