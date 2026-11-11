#include<bits/stdc++.h>
using namespace std;
const int N=500010;
const int M=1e9+10;
long long n,m;
long long a[N],dp[N];
int cmp(int x,int y)
{
    return x<y;
}
inline void solve_1()
{
    long long maxn=0;
    long long x=m;
    dp[1]=0;
    for(long long i=2;i<=n;i++)
    {
        dp[i]=dp[i-1]+(i-1)*(a[i]-a[i-1]);
        if(dp[i]<=x) maxn=max(maxn,i);
    }
    for(long long l=1;l<=n;l++)
    {
        for(long long r=l+1;r<=n;r++)
        {
            if(dp[r]-dp[l]<=m) maxn=max(maxn,r-l);
        }
    }
    cout<<maxn;
    return ;
}
inline void solve_2()
{
    long long num=1;
    long long d=a[2]-a[1];
    long long x=m;
    for(long long i=1;i<n;i++)
    {
        if(x-(i*d)>=0)
        {
            x-=i*d;
            num++;
        }
    }
    cout<<num;
    return ;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1,cmp);
    if(m>1000000000)
    {
        solve_2();
    }
    else
    {
        solve_1();
    }
    return 0;
}
