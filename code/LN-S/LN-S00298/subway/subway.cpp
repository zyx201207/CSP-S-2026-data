#include <bits/stdc++.h>
using namespace std;
int n,m,c,d,q;
int a[500330];
int b[500330];
int k[500303];
int pre=-1;
struct edge{
    int to;
    int val;
    int next;
}s[500030];

queue<int> t;

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=i;i<=n;i++)
    {
        scanf("%d",&b[i]);
        for(int j=1;j<=b[i];j++)
        {
            scanf("%d%d",&b[j],&k[j]);
        }
    }
    int g=2;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=b[j];j++)
        {
            s[g].to=b[j+1];
            s[g].next=pre;
            pre=g;
            g++;
        }
    }
    t.push(1);
    while(!t.empty())
    {
        int u=t.front();
        t.pop();
        for(int i=u;i>=0;i=s[i].next)
        {
            t.push(s[u].to);
        }

    }
    for(int w=1;w<=q;w++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
    }
    return 0;
}
