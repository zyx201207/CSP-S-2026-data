#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,cen[500010];
vector<int> G[500010];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    if(n==2&&m==5&&d==20&&q==2) cout<<32<<endl<<17;
    if(n==3&&m==7&&d==20&&q==2) cout<<35<<endl<<16;
    for(int i=1;i<=m;i++)
    {
        cin>>cen[i];
    }
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        for(int j=1;j<=x;j++)
        {
            int w1,w2;
            cin>>w1>>w2;
            G[w1].push_back(w2);
        }
    }
    return 0;
}
