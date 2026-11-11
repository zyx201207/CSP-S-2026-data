#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005],t[505][505];
vector<int>v[505];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        int k0;
        cin>>k0;
        for(int j=1;j<=k0;j++)
        {
            int tp;
            cin>>tp>>t[i][j];
            v[i].push_back(tp);
        }
    }
    while(q--)
    {
        int x,y;
        long long ans=0;
        cin>>x>>y;
        ans=w[x];
        for(int i=x;i<y;i++)
        {
            ans+=t[i][i];
            ans+=t[i][i+1];
        }
        ans+=w[y];
        cout<<ans<<'\n';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
