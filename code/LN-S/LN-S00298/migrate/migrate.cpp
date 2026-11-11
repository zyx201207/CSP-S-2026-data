#include <bits/stdc++.h>
using namespace std;
int c,t;
int a[5003000];
struct edge{
    int from;
    int to;
    int val;
    int next;
};
int pre[500300];
vector<edge> v[500200];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
   for(int w=1;w<=t;w++)
   {
        memset(pre,-1,sizeof(pre));
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(a[j]-a[i]<=m)
                {
                    v[i][j].to=j;
                    v[i][j].from=i;
                    v[i][j].val=a[j]-a[i];
                    v[i][j].next=pre[j-1];
                    pre[j]=j;
                }
            }
        }
        for(int i=1;i<=m;i++)
        {
            cout<<i<<endl;
        }
    }
    return 0;
}
