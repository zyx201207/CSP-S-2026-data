#include<bits/stdc++.h>
using namespace std;
vector<int> w;
vector<vector<int> >node,t;
int M[520][520];
int remin(int a,int b)
{
    int re=INT_MAX,sa=t[a].size()-1,sb=t[b].size()-1;
    for(int i=1;i<=sa;i++)
    {
        for(int j=1;j<=sb;j++)
        {
            re=min(re,M[node[a][i]][node[b][j]]+t[a][i]+t[b][j]);
        }
    }

    return re+w[a]+w[b];
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    //cerr<<c<<' '<<n<<' '<<m<<' '<<d<<' '<<q<<endl;
    w.push_back(0);
    node.push_back({0});
    t.push_back({0});
    memset(M,0x3f3f3f3f,sizeof(M));
    for(int i=1;i<=m;i++)
    {
        int wi;
        scanf("%d",&wi);
        w.push_back(wi);
        node.push_back({0});
        t.push_back({0});
    }

    for(int i=1;i<=n;i++)
    {
        int k;
        scanf("%d",&k);
        for(int j=1;j<=k;j++)
        {
            int ai,ti;
            scanf("%d%d",&ai,&ti);
            node[ai].push_back(i);
            t[ai].push_back(ti);
        }
    }

    for(int i=1;i<=m;i++)
    {
        int si=t[i].size()-1;
        for(int j=1;j<=si;j++)
        {

            for(int k=1;k<=si;k++)
            {
                M[node[i][j]][node[i][k]]=min(M[node[i][j]][node[i][k]],t[i][j]+t[i][k]);

            }
        }
    }
    for(int i=1;i<=n;i++) M[i][i]=0;
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                M[i][j]=min(M[i][j],M[i][k]+M[k][j]);
            }
        }
    }
    for(int i=1;i<=q;i++)
    {
        int t1,t2;
        scanf("%d%d",&t1,&t2);
        printf("%d\n",remin(t1,t2));
    }
    return 0;
}
