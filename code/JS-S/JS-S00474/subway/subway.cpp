#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=502;
const int M=5e5+2;
int c,n,m,d,q;
int w[M];
int t[M][N];
int ew[N][N];
vector<int>ve[M];
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=m;i++)
        for(int j=1;j<=m;j++)
            if(i==j) continue;
            else ew[i][j]=2e9;
    int k,a,tt;
    for(int i=1;i<=n;i++)
    {
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            cin>>a>>tt;
            ve[a].push_back(i);
            t[a][i]=tt;
        }
    }
    for(int i=1;i<=m;i++)
    {
        if(ve[i].size()<=1) continue;
        for(int jj=0;jj<=ve[i].size();jj++)
        {
            for(int kk=jj+1;kk<=ve[i].size();kk++)
            {
                int j=ve[i][jj],k=ve[i][kk];
                ew[j][k]=min(ew[j][k],t[i][j]+t[i][k]);
                ew[k][j]=ew[j][k];
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=n;k++)
            {
                ew[i][j]=min(ew[i][j],ew[i][k]+ew[k][j]);
                ew[j][i]=ew[i][j];
            }
        }
    }
    int x,y,sum;
    while(q--)
    {
        cin>>x>>y;
        sum=2e9;
        for(int i:ve[x])
        {
            for(int j:ve[y])
            {
                sum=min(sum,ew[i][j]+t[x][i]+t[y][j]);
            }
        }
        sum+=w[x]+w[y];
        cout<<sum<<'\n';
    }
    return 0;
}
