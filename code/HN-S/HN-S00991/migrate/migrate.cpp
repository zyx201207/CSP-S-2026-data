#include<bits/stdc++.h>

using namespace std;
const int N=2000000;
int n;
long long m,Ans,a[N+10],f[N+10][2];

void Work()
{
    Ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int l=1;l<n;l++)
    {
        f[l][0]=0;
        for(int i=l+1;i<=n;i++)
        {
            f[i][0]=1e9;
            for(int j=l;j<i;j++)
                if(a[i]-a[j]<=m)
                {
                    if(f[j][0]+1<f[i][0])f[i][0]=f[j][0]+1,f[i][1]=1;
                    else if(f[j][0]+1==f[i][0])f[i][1]++;
                }
            // cout<<i<<' '<<f[i][1]<<' '<<f[i][0]<<'\n';
            if(f[i][1]==2)
                Ans++;
        }
    }
    cout<<Ans<<'\n';
}

signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int c,t;
    cin>>c>>t;
    for(;t;t--)Work();
    return 0;
}