#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500009],a[509][509],t[509][509];
int w;
using pii=pair<int,int>;
priority_queue<pii,vector<pii>,greater<int>>q;
vector<pii>g[500009];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=1;j<=2*k;j++)
        {
            if(j%2==1)
            {
                cin>>a[i][j/2+1];
            }
            else
            {
                cin>>t[i][j/2];
                w=t[i][j/2];
            }
            if(j/2-1>0)g[a[i][j/2+1]].push_back({a[i][j/2-1],w});
        }

    }

    cin>>q;
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        cout<<(y-x+1)*w<<endl;
    }

}
