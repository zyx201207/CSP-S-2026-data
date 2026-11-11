#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int val[500010];
    int head=0;
    void push(int s){val[++head]=s;}
    int top()
    {
        return val[head];
    }
    void pop(){head--;}
    void clean(){head=0;}
}sts;
int n,m;
int a[500010];
int ans=0;
long long answer[300010];
bool vis[300010];
int main()
{

    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int b=1;b<=n;b++)
    {
        for(int i=b;i<=n;i++)
        {
            if(vis[a[i]]==0)
            {
                vis[a[i]]=1;
                sts.push(a[i]);
                continue;
            }
            while(sts.top()!=a[i])
            {
                vis[sts.top()]=0;
                sts.pop();
            }
        }
        for(int i=1;i<=sts.head;i++)
        {
            answer[sts.val[i]]++;
            vis[sts.val[i]]=0;
        }
        sts.clean();
    }
    for(int i=1;i<=m;i++)printf("%d ",answer[i]);
}
