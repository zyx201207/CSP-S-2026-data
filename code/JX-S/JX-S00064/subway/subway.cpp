#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],k[505];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    vector<vector<int>> t,a;
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        vector<int> p,q;
        for(int j=1;j<=2*k[i];j++)
        {
            int x,y;
            cin>>x>>y;
            p.push_back(x);
            q.push_back(y);
        }
        a.push_back(p);
        t.push_back(q);
    }
    return 0;
}
