#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<pair<int,int> > st[500005];
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q,k,a,t,x,y;
    int tr[505][505],w[500005];
    cin>>c>>n>>m>>d>>q;
    memset(tr,0x3f,sizeof(tr));
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            cin>>a>>t;
            st[a].push_back({i,t});
        }
    }
        for(int i=1;i<=m;i++)
        {
            t=st[i].size()-1;
            for(int t1=0;t1<t;t1++)
            {
                for(int t2=t1+1;t2<=t;t2++)
                {
                    a=st[i][t1].second+st[i][t2].second;
                    if(a<tr[st[i][t1].first][st[i][t2].first])
                    {
                        tr[st[i][t1].first][st[i][t2].first]=a;
                        tr[st[i][t2].first][st[i][t1].first]=a;
                    }
                }
            }
        }
    for(k=1;k<=n;k++)
    {
        for(int j=1;j<=n ;j++)
        {
            if(j==k)continue;
            for(int i=1;i<=n;i++)
            {
                if(k==i || i==j)continue;
                tr[i][j]=tr[j][i]=min(tr[i][j],tr[i][k]+tr[k][j]);
            }
        }
    }
    for(int i=1;i<=q;i++)
    {
        cin>>x>>y;
        int ans=LONG_MAX;
        for(pair<int,int> t1:st[x])
        {
            for(pair<int,int> t2:st[y])
            {
                if(t1.first!=t2.first)
                    ans=ans<(t1.second+t2.second+tr[t1.first][t2.first])?ans:(t1.second+t2.second+tr[t1.first][t2.first]);
                else
                    ans=ans<(t1.second+t2.second)?ans:(t1.second+t2.second);
            }
        }
        printf("%lld",ans+w[x]+w[y]);
        printf("%c",char(10));
    }
    return 0;
}
/*c 编号 n 线路数 m 站数 d 经过路线数 q 计划数
0 2 5 20 2
 4 1 9 2 5
 3 1 5 2 7 4 6
 3 2 3 3 4 5 7
 1 3
 1 2
 2 3
*/
