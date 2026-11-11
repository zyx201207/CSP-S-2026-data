#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int w[N],k[501],a[5000][5000],t[5000][5000],x,y;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)  cin>>w[i];
    for(int i=1;i<=n;i++){
        scanf("%d",&k[i]);
        for(int j=1;j<=k[i];j++)
            cin>>a[i][j]>>t[i][j];
    }
    int p,cost=0;
    for(int i=1;i<=q;i++){
        cin>>x>>y;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=k[i];j++)
                if(x==a[i][j])
                    p=i;
        for(int i=1;i<=k[p];i++)
            if(a[p][i]==y)
                cost+=w[x]+t[p][x]+t[p][y];
        cout<<cost<<endl;
        cost=0;
    }
    return 0;
}
