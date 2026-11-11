#include<bits/stdc++.h>
using namespace std;

typedef pair<long long,long long> pii;
long long c,T,n,d,idx,sum,x[200006],dist[200006],pre[200006];
long long h[200006],e[4000006],ne[4000006];
bool st[200006];

void add(long long a,long long b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

void dijkstra(long long start)
{
    priority_queue<pii,vector<pii>,greater<pii> > heap;
    for(int i=1 ; i<=n ; i++)
    {
        dist[i] = 0x3f3f3f3f;
        st[i] = 0;
        pre[i] = 0;
    }
    dist[0] = 0x3f3f3f3f;
    st[0] = 0;
    dist[start] = (long long)0;
    pre[start] = (long long)1;
    heap.push({(long long)0,start});
    while(heap.size())
    {
        auto u = heap.top();
        heap.pop();
        long long t = u.second;
        if(st[t])
            continue;
        st[t] = 1;
        for(long long k=h[t] ; k!=-1 ; k=ne[k])
        {
            long long y = e[k];
            if(dist[y] == dist[t]+1)
            {
                pre[y] += pre[t];
                heap.push({dist[y],y});
            }
            else if(dist[y] > dist[t]+1)
            {
                pre[y] = pre[t];
                dist[y] = dist[t]+1;
                heap.push({dist[y],y});
            }
            else
                heap.push({dist[y],y});
        }
    }
}

int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> T;
    while(T--)
    {
        sum = 0;
        cin >> n >> d;
        for(long long i=1 ; i<=n ; i++)
        {
            h[i] = -1;
            cin >> x[i];
        }
        h[0] = -1;
        for(long long i=1 ; i<n ; i++)
        {
            for(long long j=i+1 ; j<=n ; j++)
            {
                if(x[j]-x[i] <= d)
                {
                    add(i,j);
                    add(j,i);
                }
            }
        }
        for(long long i=1 ; i<n ; i++)
        {
            for(long long j=i+1 ; j<=n ; j++)
            {
                dijkstra(i);
                if(pre[j] == 2)
                    sum++;
            }
        }
        cout << sum << endl;
    }
    return 0;
}
