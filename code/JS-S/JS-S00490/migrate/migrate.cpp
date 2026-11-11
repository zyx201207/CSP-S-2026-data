#include<bits/stdc++.h>
using namespace std;
long long a[5005],f[5005][5005],s[5005];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        long long ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
                for(int k=0;k<=n;k++)
                    f[j][k]=0;
            f[i][0]=1;
            for(int j=i+1;j<=n;j++)
                for(int k=0;k<=j-i;k++)
                    for(int l=i;l<j;l++)
                        if(a[j]-a[l]<=d)
                            f[j][k]+=f[l][k-1];
            for(int j=i+1;j<=n;j++)
            {
                int ts=0;
                for(int k=j-i;k>=0;k--)
                    if(f[j][k]!=0)
                        ts=f[j][k];
                if(ts==2)
                    ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}