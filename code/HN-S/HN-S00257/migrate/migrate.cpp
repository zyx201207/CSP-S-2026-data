#include<bits/stdc++.h>
using namespace std;
long long w[5005][5005];
int Q[5005][5005];
long long c,n,m,d,q,T=0x3f3f3f3f3f3f3f3f;
void aa()
{
    for(int k=1;k<=m;k++)
    {
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(i!=j&&j!=k&&i!=k&&w[i][k]!=T&&w[k][j]!=T)
                {
                    if(w[i][j]>w[i][k]+w[k][j])
                    {
                        Q[i][j]=1;
                        w[i][j]=w[i][k]+w[k][j];
                    }
                    else if(w[i][j]==w[i][k]+w[k][j])
                    {
                        Q[i][j]++;
                    }
                }
            }
        }
    }
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n;
    long long x[200005];
    for(int t=1;t<=n;t++)
    {
        cin>>m>>q;
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=m;j++)
            {
                w[i][j]=T;
                Q[i][j]=0;
            }
        }
        for(int j=1;j<=m;j++)
        {
            w[j][j]=0;
            cin>>x[j];
        }
        for(int j=1;j<=m;j++)
        {
            for(int k=j;k<=m;k++)
            {
                if(labs(x[j]-x[k])<=q)
                {
                    long long y=labs(x[j]-x[k]);
                    w[j][k]=1;
                    w[k][j]=1;
                }
            }
        }
        /*for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cout<<(w[i][j]==T?-1:w[i][j])<<" ";
            }
            cout<<endl;
        }*/
        aa();
        long long ans=0;
        for(int i=1;i<=m;i++)
        {
            for(int j=i+1;j<=m;j++)
            {
                //cout<<Q[i][j]<<" ";
                if(Q[i][j]==2)
                {
                    ans++;
                }
            }
            //cout<<endl;
        }
        cout<<ans<<endl;
    }
}
