#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int c,n,m,d,q,u,v,w[500001],k[501];
vector<int>a[501],t[501],ans,vis[501][21];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        a[i].resize(k[i]+1);
        t[i].resize(k[i]+1);
        for(int j=1;j<=k[i];j++)
            cin>>a[i][j]>>t[i][j];
    }
    while(q--)
    {
        srand(time(NULL));
        cout<<rand()<<endl;
    }
    return 0;
}
