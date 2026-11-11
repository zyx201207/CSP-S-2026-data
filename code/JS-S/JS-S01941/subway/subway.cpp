#include<bits/stdc++.h>
using namespace std;
const int N=10000;
int c,n,m,d,q,minn=INT_MAX,x,y;
int w[N],k[N];
int a[N][N],t[N][N],record[N][N];
inline void dfs(int time,int now,int line)
{
    if(now==y) {minn=min(minn,time);return ;}
    for(int i=1;i<=n;i++)
    {
        if(record[now][i]==1)
        {
            for(int j=1;j<=k[i];j++)
            {
                if(a[i][j]!=now && i!=line) dfs(time+t[i][now]+t[i][a[i][j]],a[i][j],i);
            }
        }
    }
    return ;
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            cin>>a[i][j]>>t[i][j];
            record[a[i][j]][i]=1;
        }
    }
    for(int i=1;i<=q;i++)
    {
        minn=INT_MAX;
        cin>>x>>y;
        cout<<1;
        dfs(w[x]+w[y],x,0);
        cout<<minn<<endl;
    }
    return 0;
}
