#include<bits/stdc++.h>
using namespace std;
bool vis[500005];
int cot[500005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    stack<int> q;
    int n,m,a[500005];
    scanf("%d%d",&n,&m);
    bool flag=1;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]<a[i-1])
        {
            flag=0;
        }
    }
    if(flag)
    {
        for(int i=1;i<=m;i++)
        {
            long long num=lower_bound(a+1,a+n+1,i+1)-a-1;
            printf("%lld ",num);
        }
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if(q.empty())
            {
                q.push(a[j]);
                vis[a[j]]=1;
            }
            else
            {
                if(vis[a[j]])
                {
                    while(!q.empty())
                    {
                        if(q.top()==a[j])
                        {
                            break;
                        }
                        vis[q.top()]=0;
                        q.pop();
                    }
                }
                else
                {
                    q.push(a[j]);
                    vis[a[j]]=1;
                }
            }
        }
        while(!q.empty())
        {
            vis[q.top()]=0;
            cot[q.top()]++;
            q.pop();
        }
    }
    for(int i=1;i<=m;i++)
    {
        printf("%d ",cot[i]);
    }
    return 0;
}
