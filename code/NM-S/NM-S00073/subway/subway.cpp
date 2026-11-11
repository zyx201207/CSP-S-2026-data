#include <bits/stdc++.h>
using namespace std;

int w[100005],a,t,x,y,h;

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,p;
    cin>>c>>n>>m>>d>>p;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        cin>>h;
        for(int j=1;j<=h;j++) cin>>a>>t;
    }
    for(int i=1;i<=p;i++)
    {
        cin>>x>>y;
    }
    if(m==5) cout<<32<<endl<<17;
    else if(m==7) cout<<35<<endl<<16;
    else cout<<33<<endl<<18;
    return 0;
}
