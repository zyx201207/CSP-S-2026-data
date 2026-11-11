#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],maxn=-1,cnt;
int used[200005];
bool b[10000005];
void dfs(int u)
{
    if(cnt==m)
    {
        bool flag=false;
        int k;
        for(int i=1;i<=n;i++)
        {
            if(used[i]!=0&&!flag)
            {
                flag=true;
                k=a[used[i]];
            }
            else if(used[i]!=0)
            {
                k&=a[used[i]];
            }
        }
        maxn=max(maxn,k);
        return ;
    }
    for(int i=1;i<=n;i++)
    {

        if(used[u]==0&&!b[i])
        {
            b[i]=true;
            used[u]=i;
            cnt++;
            dfs(u+1);
            cnt--;
            used[u]=0;
            b[i]=false;
        }
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
    dfs(1);
    cout<<maxn;
    return 0;
}
