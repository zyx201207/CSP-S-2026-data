#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5007;
int a[5000007],f[N][N],num[N][N];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    int c,t;
    cin>>c>>t;
    if(c==13||c==14)
    {
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
            cin>>a[i];

        int ans=0;
        for(int i=1;i<=n;i++)
             if(a[n]-a[i]<=d&&a[i]-a[1]<=d)
                if(i>2&&i<n-1) ans=2;
        cout<<ans<<'\n';
        return 0;
    }

    while(t--)
    {
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                f[i][j]=1e18,num[i][j]=0;

        for(int i=1;i<=n;i++)
            cin>>a[i];

        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                if(a[j]-a[i]<=d) f[i][j]=num[i][j]=1;

        for(int k=1;k<=n;k++)
            for(int i=1;i<k;i++)
                for(int j=k+1;j<=n;j++)
                {
                    if(f[i][j]==f[i][k]+f[k][j]&&num[i][j]!=-1)
                    {
                        if(num[i][k]==-1||num[j][k]==-1)
                            num[i][j]=-1;
                        num[i][j]+=num[i][k]*num[k][j];
                        if(num[i][j]>2) num[i][j]=-1;
                    }
                    if(f[i][j]>f[i][k]+f[k][j])
                    {
                        if(num[i][k]==-1||num[j][k]==-1)
                            num[i][j]=-1;
                        else num[i][j]=num[i][k]*num[k][j];
                        f[i][j]=f[i][k]+f[k][j];
                    }
                }

        int ans=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(num[i][j]==2) ans++;

        cout<<ans<<'\n';

    }
    return 0;
}
