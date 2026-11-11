#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,x,y,jt;
vector<pair<int,int>> a[505];
int w[500005],k[505],dd[500005];
long long anss[500005];
bool tf;
struct three
{
    int a,b,c;
} qq[100005];
bool cmp(three e,three f)
{
    return e.a<f.a;
}
void f(int qi)
{
    queue<pair<int,int>> t;
    t.push(make_pair(qi,0));
    while(t.size())
    {
        auto [nq,nd]=t.front();
        t.pop();
        for(int i=1;i<=n;i++)
        {
            tf=0;
            for(int j=1;j<=k[i];j++)
                if(a[i][j].first==nq) tf=1,jt=a[i][j].second;
            if(!tf) continue;
            for(int j=1;j<=k[i];j++)
            {
                if(a[i][j].first==nq) continue;
                auto [u,tt]=a[i][j];
                if(dd[u]>nd+tt+jt ||dd[u]==-1)
                {
                    dd[u]=nd+tt+jt;
                    t.push(make_pair(u,dd[u]));
                }
            }
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        a[i].push_back(make_pair(0,0));
        for(int j=1;j<=k[i];j++)
        {
            cin>>x>>y;
            a[i].push_back(make_pair(x,y));
        }
    }
    for(int i=1;i<=q;i++)
    {
        cin>>qq[i].a>>qq[i].b;
        qq[i].c=i;
    }
    sort(qq+1,qq+q+1,cmp);
    for(int i=1;i<=q;i++)
    {
        memset(dd,-1,sizeof(dd));
        dd[qq[i].a]=0;
        f(qq[i].a);
        int j=i;
        for(j=i;j<=q;j++)
        {
            if(qq[j].a==qq[i].a) anss[qq[j].c]=w[qq[i].a]+w[qq[j].b]+dd[qq[j].b];
            else break;
        }
        i=j-1;
    }
    for(int i=1;i<=q;i++) cout<<anss[i]<<endl;
    return 0;
}
