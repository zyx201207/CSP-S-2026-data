#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    long long c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    long long  w[m],k[n];
    for(long long i=0;i<m;i++)
    {
        cin>>w[i];
    }
    long long t[n][m],a[n][m],s[n][m];
    for(long long i=0;i<n;i++)
    {
        cin>>k[i];
        for(long long j=0;j<k[i];j++)
        {
            cin>>a[i][j]>>t[i][j];
            s[i][j]=1;
        }
    }
    if(n==2)
    {
        long long res=1e18;
        for(long long i=0;i<n;i++)
        {
                res=min(t[1][i]+t[0][i],res)
        }
        for(long long i=0;i<q;i++)
        {
            long long x,y;
            cin>>x>>y;
            if((s[1][x]==1 and s[1][y]==1) or (s[0][x]==1 and s[0][y]==1))
            {
                if((s[1][x]==1 and s[1][y]==1) and t[1][x]+t[1][y]<t[0][x]+t[0][y])
                    cout<<w[x]+w[y]+t[1][x]+t[1][y];
                else
                    cout<<w[x]+w[y]+t[1][x]+t[1][y];
            }
            else{
                cout<<w[x]+w[y]+t[max(s[1][x],s[0][x])][x]+t[max(s[1][y]+s[2][y])][y]+res;
            }

        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}

