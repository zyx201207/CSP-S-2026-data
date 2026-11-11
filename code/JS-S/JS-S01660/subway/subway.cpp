#include<bits/stdc++.h>
using namespace std;
struct node{
    int u;
    int w;
};
vector<node> a[500505];
int dis[500505];
int ww[500005];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int c,m,n,d,q,ans=0;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>ww[i];
    }
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        ans+=2*k;
        for(int j=1;j<=k;j++)
        {
            int ai,ti;
            cin>>ai>>ti;
            a[ai].push_back({m+i,ti});
            a[m+i].push_back({ai,ti});
        }
    }
    for(int i=1;i<=q;i++)
    {
        int s,e;
        cin>>s>>e;
        memset(dis,0x7f,sizeof(dis));
        dis[s]=0;
        for(int j=1;j<=ans;j++)
        {
            for(int k=1;k<=m+n;k++)
            {
                for(auto it=a[k].begin();it!=a[k].end();it++)
                {
                    node h=*it;
                    dis[k]=min(dis[k],dis[h.u]+h.w);
                }
            }
        }
        cout<<dis[e]+ww[s]+ww[e]<<'\n';
    }
    return 0;
}