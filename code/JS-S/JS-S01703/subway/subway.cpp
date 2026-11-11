#include <bits/stdc++.h>
using namespace std;
vector<long long> z[1005];
long long ans[1005];
struct S{
    long long id;
    long long va;
}p[1005];
long long val[1005][1005];
bool cmp(S a,S b)
{
    return a.va>b.va;
}
long long T;
long long W[505];
long long lx[505];
long long Z[500005][505];
vector<long long> f[500005];
long long is[1005];
long long su;
int main()
{
 //   freopen("subway.in","r",stdin);
 //   freopen("subway.out","w",stdout);
    long long C,N,M,D,Q;
    cin>>C>>N>>M>>D>>Q;
    for(int q=1;q<=M;q++)
    {
        cin>>W[q];
    }
    for(int q=1;q<=N;q++)
    {
        int k;
        cin>>k;
        for(int w=1;w<=k;w++)
        {
            long long a,b;
            cin>>a>>b;
            Z[a][q]=b;
            f[a].push_back(q);
            int ty=f[a].size();
            if(ty>=2)
            {
                su++;
                is[su]=a;
            }
        }
    }
    for(int R=0;R<=1005;R++)
    {
        for(int yt=0;yt<=1005;yt++)
        {
            val[R][yt]=1e12;
        }
    }
    for(int q=1;q<=su;q++)
    {
        vector<long long> tm;
        for(auto w:f[is[q]])
        {
            for(auto e:tm)
            {
                z[e].push_back(w);
                z[w].push_back(e);
                val[e][w]=min(val[e][w],Z[q][w]+Z[q][e]);
                val[w][e]=min(val[w][e],Z[q][w]+Z[q][e]);
            }
            tm.push_back(w);
        }
    }
    for(int R=1;R<=Q;R++)
    {
        for(int yt=0;yt<=1005;yt++)
        {
            ans[yt]=1e12;
        }
        T=0;
        T++;
        long long Y,t,tt;
        cin>>t>>Y;
        for(auto q:f[t])
        {
            for(auto w:f[Y])
            {
                if(q==w)
                {
                    tt=q;
                    Y=q;
                    break;
                }
                if(tt=Y)break;
            }
        }
        if(tt!=Y)
        {
            tt=f[t][0];
            Y=f[t][0];
        }
        p[T].id=tt;
        p[T].va=W[tt];
        while(T>0)
        {
            S q=p[T];
            T--;
            ans[q.id]=q.va;
            for(auto w:z[q.id])
            {
                if(ans[q.id]+val[q.id][w]<=ans[w])
                {
                    T++;
                    p[T].id=w;
                    p[T].va=ans[q.id]+val[q.id][w];
                }
            }
            sort(p+1,p+1+T,cmp);
        }
        cout<<2*ans[Y]+W[Y]<<" ";
    }
    return 0;
}
