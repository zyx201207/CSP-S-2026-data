#include<bits/stdc++.h>
using namespace std;
const int MAXM=500005;
// const long long INF=1e18;
// typedef pair<long long,int> PLI;
// vector<PLI> adj[MAXM];
// long long dist[MAXM];

int w[MAXM];
struct subbbbbb{
    int a;
    int t;
}line[MAXM];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=0;i<n;i++)
    {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            cin>>line[j].a>>line[j].t;
        }
    }
    for(int i=0;i<q;i++)
    {
        int x,y;
        cin>>x>>y;
        cout<<w[x]+w[y]<<endl;
    }
}