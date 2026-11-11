#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;

int c,n,m,d,q;
int w[N];
int k;
struct node
{
    int to,nxt,id;
    long long wet;
}edge[2*N];
int head[N],num_edge;
int x,y;
long long f[500][500],z;

void add(int e,int a,int t,int i)
{
    edge[++num_edge].nxt=head[e];
    edge[num_edge].to=a;
    edge[num_edge].wet=t;
    edge[num_edge].id=i;
    head[e]=++num_edge;
}

void dijkstra()
{
    for(int i=1;i<=n;i++)  f[i][i]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=head[i];j;j=edge[i].nxt)
        {
            int v=edge[j].to;
            f[i][v]=min(f[i][v],edge[i].wet);
        }
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)  f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
        }
    }
}

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)  cin>>w[m];
    for(int i=1;i<=n;i++)
    {
        int a,t,e;
        cin>>k;
        cin>>a>>t;
        e=a;
        add(0,a,t,i);
        for(int j=2;j<=k;j++)
        {
            cin>>a>>t;
            add(e,a,t,i);
            e=a;
        }
    }
    dijkstra();
    while(q--)
    {
        cin>>x>>y;
        cout<<f[x][y]+w[x]+w[y]<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}



