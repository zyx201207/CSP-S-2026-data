#include<bits/stdc++.h>
using namespace std;
long long w[1005][1005],W[1005];
int a[500005],t[500005],k;
int c,n,m,d,q;
void aa()
{
    for(int k=1;k<=m;k++)
    {
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=m;j++)
            {
                w[i][j]=min(w[i][j],w[i][k]+w[k][j]);
            }
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=m;j++)
        {
            w[i][j]=0x3f3f3f3f3f3f3f3f;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cin>>W[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>k;
        for(int i=1;i<=k;i++)
        {
            cin>>a[i]>>t[i];
        }
        for(int j=1;j<=k;j++)
        {
            for(int m=1;m<=k;m++)
            {
                w[a[j]][a[m]]=min(w[a[j]][a[m]],1ll*t[j]+t[m]);
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        w[i][i]=0;
        /*for(int j=1;j<=m;j++)
        {
            cout<<(w[i][j]==0x3f3f3f3f3f3f3f3f?-1:w[i][j])<<" ";
        }
        cout<<endl;*/
    }
    aa();
    for(int i=1;i<=q;i++)
    {
        int u,v;
        cin>>u>>v;
        cout<<w[u][v]+W[u]+W[v]<<endl;
    }
}
