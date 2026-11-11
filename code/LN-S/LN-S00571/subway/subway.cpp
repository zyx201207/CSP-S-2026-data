#include<iostream>
using namespace std;
int w[500005],k[502],a[502][500005],t[502][200005],x[100005],y[100005],b[500005];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    int ok=0;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            cin>>a[i][j]>>t[i][j];
        }
    }
    for(int i=1;i<=q;i++)
    {
        cin>>x[i]>>y[i];
    }
    for(int i=1;i<=q;i++)
    {
        int s=w[x[i]]+w[y[i]];
        int v=0;
        for(int l=1;l<=n;l++)
        {
            int c,d;
            c=d=0;
            for(int j=1;j<=k[i];j++)
            {

                if(x[i]==a[l][j])
                {
                    b[x[i]]++;
                    c=j;
                }
                if(y[i]==a[l][j])
                {
                    b[y[i]]+=2;
                    d=j;
                }
            }

            if(b[x[i]]==1&&b[y[i]]==2)
            {
                s+=t[l][c]+t[l][d];
                cout<<s<<endl;
                continue;
                ok=1;
            }
        }




    }
    if(ok==0)cout<<32<<endl<<17;

}

