#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int c,n,m,dd,q,minn=1e9;
int d[N],dp[505][505],a[5];
struct Edge
{
    int to,len;
};
vector<Edge> G[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n;
    cin>>m>>dd>>q;
    for(int i=1;i<=m;i++)
        cin>>d[i];

    for(int i=1;i<=n;i++)
    {
        int k,u,w;
        cin>>k;
        for(int j=1;j<=2*k;j++)
        {

            cin>>u>>w;
            a[u]=w;
        }
    }
    for(int i=1;i<=q;i++)
    {
        int x,y;
        cin>>x>>y;
        cout<<d[x]+d[y]+a[x]+a[y]<<endl;
    }
    return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
