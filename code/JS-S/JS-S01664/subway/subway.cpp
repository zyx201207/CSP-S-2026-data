#include<bits/stdc++.h>
using namespace std;
#define intt long long
int c,n,m,d,q;
intt di[1005][1005];
const int M=5e5+5;
intt k[1005];
intt ww[1005];
intt a[1005][1005];
intt t[1005][1005];

intt flo[1005][1005];
intt w[1005][1005];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for (int i=1;i<=m;i++)
    {
        cin>>ww[i];
    }
    for (int i=1;i<=n;i++)
    {
        cin>>k[i];
        for (int j=1;j<=k[i];j++)
        {
            cin>>a[i][j]>>t[i][j];

        }
    }
    for (int i=1;i<=m;i++)
        for (int j=1;j<=m;j++)
           w[i][j]=INT_MAX;
    for (int i=1;i<=m;i++)
            w[i][i]=0;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=k[i];j++)
        {
            for (int kk=j+1;kk<=k[i];kk++)
            {
               //cout<<a[i][j]<<' '<<a[i][kk]<<' '<<t[i][j]<<' '<<t[i][kk]<<'\n';
                w[a[i][j]][a[i][kk]]=min(w[a[i][j]][a[i][kk]],t[i][j]+t[i][kk]);
                w[a[i][kk]][a[i][j]]=min(w[a[i][kk]][a[i][j]],t[i][j]+t[i][kk]);

            }
        }
    }
    /*for (int i=1;i<=m;i++)
    {
        for (int j=1;j<=m;j++)
        {
            cout<<w[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<'\n';*/
    for (int i=1;i<=m;i++)
        for (int j=1;j<=m;j++)
           flo[i][j]=INT_MAX;
    for (int i=1;i<=m;i++)
        flo[i][i]=0;
    for (int k=1;k<=m;k++)
    {
        for (int i=1;i<=m;i++)
        {
            for (int j=1;j<=m;j++)
            {
                //if (w[k][j]!=INT_MAX)
                {
                    flo[i][j]=min(flo[i][j],flo[i][k]+w[k][j]);
                    flo[j][i]=min(flo[j][i],flo[i][k]+w[k][j]);
                    //flo[i][k]=min(flo[i][k],flo[i][j]+w[j][k]);
                }
            }
        }
    }
    /*cout<<"hyw\n";
    for (int i=1;i<=m;i++)
    {
        for (int j=1;j<=m;j++)
        {
            cout<<flo[i][j]<<' ';
        }
        cout<<'\n';
    }*/
    int s,e;
    while (q--)
    {
        cin>>s>>e;
        /*if (flo[s][e]==INT_MAX)
            cout<<"klbq";*/
        cout<<flo[s][e]+ww[s]+ww[e]<<'\n';
    }
    return 0;
}
/*
4
1 2 2
1 3 5
2 4 1
2 3 2









*/
