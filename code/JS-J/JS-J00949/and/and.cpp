#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[200010];
int maxn=-2e9;
int n,m;
void dfs(int step,int sum,int ch)
{
        if(step>n||ch>=m)
        {
            if(ch==m)
            {

            maxn=max(maxn,sum);
            }
            return;
        }
        if(ch!=0)
        {
             dfs(step+1,sum&a[step],ch+1);
        }
        else{

        dfs(step+1,a[step],ch+1);
        }
        dfs(step+1,sum,ch);
}
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i <= n;i++)cin>>a[i];
    dfs(1,0,0);
    cout<< maxn;
    return 0;
}
