#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int ans=-1;
int a[200009];
void dfs(int sum,int t,int s)
{
    if(s==m)
    {
        ans=max(ans,sum);
        return;
    }
    if(t>=n)
    {
        return;
    }
    int f=sum&a[t];
    dfs(f,t+1,s+1);
    dfs(sum,t+1,s);
}
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        dfs(a[i],i+1,1);
    }
    cout<<ans;
    return 0;
}

