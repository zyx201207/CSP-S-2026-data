#include<bits/stdc++.h>
using namespace std;
vector<int>g[500005];
int n,m,d,q,w[500005];
long long f[1001][1001];
int t[1001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) f[i][j]=1e12;
    for(int i=1;i<=m;i++){cin>>w[i];}
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;vector<int>q;
        for(int j=1;j<=k;j++){
            int a;cin>>a>>t[a];
            for(int b:q){f[b][a]=f[a][b]=t[a]+t[b];}
            q.push_back(a);
        }
    }
    for(int i=1;i<=m;i++)
    {

        for(int j=1;j<=m;j++)
            cout<<f[i][j]<<' ';
        cout<<endl;
    }
    for(int k=1;k<=m;k++)
    {
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(i==k||k==j) continue;
                if(f[i][k]+f[k][j]<f[i][j])
                    f[i][j]=f[i][k]+f[k][j];
            }
        }
    }
    for(int i=1;i<=q;i++)
    {
        int x,y;
        cin>>x>>y;
        cout<<t[x]+t[y]+f[x][y]+w[x]+w[y]<<'\n';
    }
    return 0;
}
