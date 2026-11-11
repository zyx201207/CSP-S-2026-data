#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000000],Max=-1,f=0;
void dfs(long long x,long long b[1000000])
{
    if(f)return;
    long long MAX=-1,cnt=0;
    for(long long i=0;i<n-1;i++)
    {
        if(b[i]==b[i+1])
        {
            cnt++;
            MAX=max(cnt+1,MAX);
        }
        else cnt=0;
    }
    if(MAX==n)
    {
        f=1;
        cout<<n;
    }
    Max=max(Max,MAX);
    if(x==m)
    {
        for(long long i=0;i<n;i++)
        {
            b[i]=a[i];
        }
        return;
    }
    for(long long i=0;i<n;i++)
    {
        b[i]++;
        dfs(x+1,b);
        b[i]--;
    }
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(long long i=0;i<n;i++)
    {
        cin>>a[i];
    }
    dfs(0,a);
    if(f)return 0;
    cout<<Max;
}
