#include<bits/stdc++.h>
using namespace std;
const long long INF=0x3fffffffffffffff;
inline long long read()
{
    char c=getchar();
    while (!isdigit(c))
        c=getchar();
    long long ans=0;
    while (isdigit(c))
    {
        ans=ans*10+c-48;
        c=getchar();
    }
    return ans;
}
void write(const long long x)
{
    if (x>9)
        write(x/10);
    putchar(x%10+48);
    return;
}
struct node
{
    int id;
    long long t;
};
long long w[500001],dis[501][501];
vector<node>line[500001];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    const long long c=read(),n=read(),m=read(),d=read();
    int q=read();
    for (long long i=1;i<=m;++i)
        w[i]=read();
    for (long long i=1;i<=n;++i)
    {
        const long long k=read();
        for (long long j=1;j<=k;++j)
            line[read()].emplace_back((node){i,read()});
    }
    for (long long i=1;i<=n;++i)
        for (long long j=1;j<=n;++j)
            if (i!=j)
                dis[i][j]=INF;
    for (long long i=1;i<=m;++i)
        for (long long j=0;j<line[i].size();++j)
            for (long long k=j+1;k<line[i].size();++k)
            {
                const long long s=line[i][j].t+line[i][k].t;
                dis[line[i][j].id][line[i][k].id]=s;
                dis[line[i][k].id][line[i][j].id]=s;
            }
    for (long long k=1;k<=n;++k)
        for (long long i=1;i<=n;++i)
            for (long long j=1;j<=n;++j)
                if (dis[i][j]>dis[i][k]+dis[k][j])
                {
                    dis[i][j]=dis[i][k]+dis[k][j];
                    dis[j][i]=dis[i][k]+dis[k][j];
                }
    while (q--)
    {
        const long long x=read(),y=read();
        long long ans=INF;
        for (const node&i:line[x])
            for (const node&j:line[y])
                ans=min(ans,i.t+j.t+dis[i.id][j.id]);
        write(ans+w[x]+w[y]);
        putchar('\n');
    }
    return 0;
}