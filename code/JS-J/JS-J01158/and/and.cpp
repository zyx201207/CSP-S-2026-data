#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],ans=-1;
long long dfs(long long c,long long b,long long sum)
{
    if(b==m)
        return sum;
    else if(c==n-1)
        return 0;
    sum=max(dfs(c+1,++b,sum&=a[c+1]),dfs(c+1,b,sum));
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    cin>>n>>m;
    for(long long i=0;i<n;i++)
        cin>>a[i];
    for(long long i=0;i<n-m+1;i++)
        ans=max(ans,dfs(i,1,a[i]));
    cout<<ans;
    return 0;
}
