#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long w[5000005];
bool u[5000005];
long long kw[5000005];
long long k;
struct node
{
    long long road[500005];
    long long point[500005];
    long long f=1;
    bool v=1;
}Map[500005];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(long long i=1;i<=m;i++)
        cin>>w[i];
    for(long long i=1;i<=n;i++)
    {
        cin>>k;
        for(long long j=1;j<=k;j++)
        {
            long long a,b;
            cin>>a>>b;
             Map[a].point[Map[a].f]=a+i;
            Map[a].road[Map[a].f++]=b;
            Map[i+a].point[Map[i+a].f]=a;
            Map[i+a].road[Map[i+a].f++]=b;
        }
    }
    for(long long i=1;i<=q;i++)
    {
        long long x,y;
        cin>>x>>y;
        queue<long long>past;
        queue<long long>old;
        past.push(w[x]+w[y]);
        old.push(x);
        for(long long j=1;j<=n+m;j++)
        {
            Map[j].v=1;
        }
        while(!past.empty())
        {
            long long get=old.front(),getl=past.front();
            Map[get].v=0;
            for(long long j=1;j<=Map[get].f;j++)
            {
                long long l=Map[get].point[j-1];
                if(!Map[l].v)
                {
                    kw[l]=min(kw[l],getl+Map[get].road[j-1]);
                }
                else
                {
                    kw[l]=getl+Map[get].road[j-1];
                    old.push(l);
                    past.push(kw[l]);
                }
            }
        }
        cout<<kw[y]<<endl;
    }
    return 0;
}
