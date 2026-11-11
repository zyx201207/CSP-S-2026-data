#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int c,t;
long long a[2000005];
long long sum[5005];
long long f[5005][5005];
long long ert[5005][5005];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int tt=1;tt<=t;tt++)
    {
        memset(f,0,sizeof(f));
        int n;
        long long m;
        cin>>n>>m;
        sum[0]=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            sum[i]=sum[i-1]+a[i];
        }
        for(int i=1;i<=n-1;i++)
        {
            f[i][i+1]=1;
            ert[i][i+1]=1;
        }
        long long anss=0;
        for(int len=2;len<=n-1;len++)
        {
            for(int l=1;l<=n-len;l++)
            {
                int r=l+len;
                ert[l][r]=0x3f3f3f3f3f;
                for(int k=l+1;k<r;k++)
                {
                    if(ert[l][k]+ert[k][r]<ert[l][r])
                    {
                        f[l][r]=f[l][k]*f[k][r];
                        ert[l][r]=min(ert[l][r],ert[l][k]+ert[k][r]);
                    }
                    if(ert[l][k]+ert[k][r]==ert[l][r])
                    {
                        f[l][r]+=f[l][k]*f[k][r];
                    }
                }
                if(sum[r]-sum[l-1]<=m&&ert[l][r]==1)
                {
                    f[l][r]++;
                }
                if(sum[r]-sum[l-1]<=m&&ert[l][r]!=1)
                {
                    f[l][r]=1;
                    ert[l][r]=1;
                }
                if(f[l][r]==2)
                {
                    anss++;
                }
            }
        }
        cout<<anss<<endl;
    }
    return 0;
}
