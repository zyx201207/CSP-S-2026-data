#include<bits/stdc++.h>
using namespace std;
int a[200010];
int maxn=-1;
int n,m;
void dfs(int now,int step,int sum)
{
    if(step==m+1)
    {
        maxn=max(maxn,sum);
        return;
    }
    for(int i=now;i<=n;i++)
    {
        if(step==1)
            sum=a[i];
        dfs(i+1,step+1,sum&a[i]);
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    dfs(1,1,0);
    cout<<maxn;
    return 0;
}
