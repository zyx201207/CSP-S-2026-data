#include <bits/stdc++.h>
using namespace std;
long long n,m,ans[200010],maxn=-0x3f;
long long a[200010];
long long dp[200010];
void dfs(int cs,int t)
{
    if(cs==m+1)
    {
        maxn=max(maxn,ans[cs-1]);
        return;
    }
    else
    {
        for(int i=t;i<=n;i++)
        {
            if(cs==1)
            {
                ans[cs]=a[i];
            }
            else ans[cs]=ans[cs-1]&a[i];
            dfs(cs+1,i+1);
        }//4 2
        //5 13 12 12
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
    dfs(1,1);
    cout<<maxn<<endl;
    return 0;
}
