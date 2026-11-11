#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
bool a[200000+500][40];
bool vis[200000+500];
int ans[30];
void dfs(int root)
{
    if(root==0)
    {
        return;
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]) continue;
        if(a[i][root]) cnt++;
    }
    if(cnt<m)
    {
        ans[root]=0;
        dfs(root-1);
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i]) continue;
        if(!a[i][root]) vis[i]=true;
    }
    ans[root]=1;
    dfs(root-1);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin >> x;
        int cnt=1;
        while(x>0)
        {
            a[i][cnt]=(x%2);
            cnt++;
            x=x/2;
        }
    }
    dfs(31);
    int sum=0;
    for(int i=1;i<=31;i++)
    {
        sum=sum+(ans[i]<<(i-1));
    }
    cout << sum << endl;

    return 0;
}