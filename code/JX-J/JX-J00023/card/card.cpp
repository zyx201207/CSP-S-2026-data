#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;
int n,m;
stack<int> q;
bool vis[maxn];
int a[maxn],ans[maxn];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++)
    {
        memset(vis,0,sizeof(vis));
        for(int now=i;now<=n;now++)
        {
            if(vis[a[now]])
            {
                while(q.top() != a[now]) q.pop();
                vis[a[now]] = 1;
            }
            else q.push(a[now]),vis[a[now]] = 1;
        }
        while(q.size())
        {
            ans[q.top()] ++;
            q.pop();
        }
    }
    for(int i=1;i<=m;i++) printf("%d ",ans[i]);
    puts("");
    return 0;
}