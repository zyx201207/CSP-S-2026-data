#include<bits/stdc++.h>
using namespace std;
long long  n,m;
long long a[500005];
int f(int i)
{
    int flag=i-1,ans=1;
    long long sum=0;
    while(sum<=m)
    {
        if(flag<1)return i;
        if(a[i]-a[flag]>m-sum)return ans;
        if(sum+a[i]-a[flag]<=m)
        {
            ans++;
            sum+=a[i]-a[flag];
            flag--;
        }
    }
    return ans;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(),cin.tie(),cout.tie();
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    int maxn=-INT_MAX;
    for(int i=1;i<=n;i++)
    {
        maxn=max(maxn,f(i));
        if(maxn==n)
        {
            cout<<n;
            return 0;
        }
    }
    cout<<maxn;
    return 0;
}
