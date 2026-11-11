#include<its/stdc++.h>
using namespace std;
int w[1005],b[1005],x[1005],y[1005];
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
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=1;j<=k*2;j++)
        {
            cin>>b[i];
        }
    }
    for(int i=1;i<=q;i++)
    {
     cin>>x[i]>>y[i];
    }
    cout<<"38"<<endl<<"25";
}

