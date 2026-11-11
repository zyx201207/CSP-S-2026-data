#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
vector<pair<int,int>> g[N];
ll w[N];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    vector<vector<int>> t(m+5,vector<int>(n+5));
    for(int i=1;i<=n;i++)
    {
        int k,last;
        cin>>k>>last;
        for(int j=2;j<=k;j++)
        {
            int a;
            cin>>a;
            cin>>t[a][i];
            g[last].push_back({a,i});
            g[a].push_back({last,a});
        }
    }
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        cout<<x+y<<'\n';
    }
    return 0;
}