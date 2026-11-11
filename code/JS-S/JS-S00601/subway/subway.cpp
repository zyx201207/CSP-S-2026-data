#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
#define PP pair<long long,long long>
priority_queue<PP,vector<PP >,greater<PP > >qq;
long long z[500005];
long long w[500005];
struct node
{
    long long h[505]={};
}a[500005];
struct nade
{
    vector<long long>jd;
}b[505];
long long dj(long long x,long long y)
{
    while(!qq.empty())
    {
        long long l=qq.top().first;
        long long r=qq.top().second;
        qq.pop();
        while((!qq.empty())&&l>z[r])
        {
            long long l=qq.top().first;
            long long r=qq.top().second;
            qq.pop();
        }
        if(qq.empty()&&l>z[r])
        {
            break;
        }
        for(long long i=1;i<=n;i++)
        {
            if(a[r].h[i]!=0)
            {
                for(long long j=0;j<b[i].jd.size();j++)
                {
                    long long kkk=b[i].jd[j];
                    if(z[kkk]==1e16||z[r]+a[r].h[i]+a[kkk].h[i]<z[kkk])
                    {
                        z[kkk]=z[r]+a[r].h[i]+a[kkk].h[i];
                        qq.push({z[kkk],kkk});
                    }
                }
            }
        }
    }
    return z[y];
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(long long i=1;i<=m;i++)
    {
        cin>>w[i];
    }
        for(long long i=1;i<=n;i++)
        {
            long long k;
            cin>>k;
            for(long long j=1;j<=k;j++)
            {
                long long x,y;
                cin>>x>>y;
                a[x].h[i]=y;
                b[i].jd.push_back(x);
            }
        }
        for(long long i=1;i<=q;i++)
        {
            long long x,y;
            cin>>x>>y;
            for(long long j=1;j<=m;j++)
            {
                z[j]=1e16;
            }
            z[x]=0;
            qq.push({0,x});
            cout<<dj(x,y)+w[x]+w[y]<<endl;
        }
    return 0;
}
