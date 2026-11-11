#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+5,M=1e5+5;
ll c,n,m,d,q,x[M],y[M],w[N],k[505],a[505][N],t[505][N],crs[N],ans[N],p=1,o[N],flash[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>p;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i]*2;j++)
        {
            if(j%2==1)
            {
                cin>>a[i][(j+1)/2];
            }
            else
            {
                cin>>t[i][j/2];
            }
        }
    }
    for(int i=1;i<=q;i++)
    {
        cin>>x[i]>>y[i];
    }
     for(int i=1;i<=q;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int z=1;z<=k[i];z++)
            {
                if(a[j][z]==x[i])
                {
                    for(int o=1;o<=q;o++)
                {
                    for(int p=1;p<=n;p++)
                        {
                            for(int s=1;s<=k[o];s++)
                                {
                                    if(a[p][s]==y[o])
                                            {
                                                cout<<t[j][z]+t[p][s];
                                                return 0;
                                            }
                                }
                        }
                }
                }
            }
        }
    }
    return 0;
}
