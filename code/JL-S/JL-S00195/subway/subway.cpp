
#include<bits/stdc++.h>
using namespace std;
#define int long long

struct node{
    int v,w;
};
int c,n,m,d,q;
int arr[1000000];
vector<node> mapp[1000000];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    
    for(int i=1;i<=m;i++)
    {
        int te2;
        cin>>te2;
        arr[i]=te2;
    }
    for(int i=1;i<=n;i++)
    {
        int qq;
        cin>>qq;
        for(int j=0;j<qq;j++)
        {
            int te1,te2;
            cin>>te1>>te2;
            mapp[te1].push_back({i+m,te2});
            mapp[i+m].push_back({te1,te2});
        }
    }
for(int i=0;i<q;i++)
{
    int aaa,bbb;
    cin>>aaa>>bbb;
    int ans=arr[aaa]+arr[bbb];
    int dist[1000000];
    for(int j=0;j<1000000;j++)  dist[j]=1e9;
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
    pq.push({aaa,0});
    dist[aaa]=0;
    while(!pq.empty())
    {
        int x=pq.top().first;
        int y=pq.top().second;
        pq.pop();
        if(y>dist[x])
            continue;
        for(auto no:mapp[x])
        {
            //cout<<"!";
            int v=no.v;
            int w=no.w;
            if(dist[v]>dist[x]+w)
            {
                dist[v]=dist[x]+w;
                pq.push({v,dist[v]});
            }
        }
    }
    ans+=dist[bbb];
    cout<<ans<<"\n";
}
    return 0;
}