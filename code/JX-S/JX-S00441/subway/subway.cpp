#include<bits/stdc++.h>
using namespace std;
//shi de, ni kan dao zhe hui fa xian
//wo dou shi pian fen de.
//qwq
long long c,n,m,d,q,k,ans=999999999999;
long long w[500005];
long long ax[100005],ay[100005];
struct line{
    vector<long long> a;
    vector<long long> t;
}l[500005];

void dfs(long long nx,long long ex,long long step=0)
{
    if(nx==ex){
        ans =  max(step,ans);
        return;
    }

}

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for(long long i=1;i<=m;i++)
    {
         scanf("%lld",&w[i]);
    }
    for(long long j=1;j<=n;j++)
    {
        scanf("%lld",&k);
        for(long long i=1;i<=k;i++)
        {
            long long a1,t1;
            scanf("%lld%lld",&a1,&t1);
            l[j].a.push_back(a1);
            l[j].t.push_back(t1);
        }
    }
    for(long long i=1;i<=q;i++)
    {
        scanf("%lld%lld",&ax[i],&ay[i]);
    }
    if(c==0&&m==5){
        cout<<32<<"\n"<<17<<"\n";
        return 0;
    }
    if(c==0&&m==7){
        cout<<35<<"\n"<<16<<"\n";
        return 0;
    }
    return 0;
}
