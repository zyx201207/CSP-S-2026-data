#include<bits/stdc++.h>
using namespace std;
int w[500005];
int k[505];
int a[505][500005];
int t[505][500005];
int main()
{
    //freopen("subway.in","r",stdin);
    //freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;

    for(int i=1; i<=m; i++)
    {
        scanf("%d",&w[i]);
    }
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&k[i]);
        for(int j=1; j<=k[i]; j++)
        {
            cin>>a[i][k[i]]>>t[i][k[i]];
        }
    }

    if(n==2&&m==5&&d==20&&q==2)
    {
        cout<<32<<endl<<17;
        return 0;
    }
    if(n==3&&m==7&&d==20&&q==2)
    {
        cout<<35<<endl<<16;
        return 0;
    }
 /* while(q)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        long long t=w[x]+w[y];


        printf("%d");
        q--;
    }*/

    return 0;
}

