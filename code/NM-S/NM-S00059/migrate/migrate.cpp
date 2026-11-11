#include<bits/stdc++.h>
using namespace std;
long long x[2000001],ans,c,d,n,t;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        for(long long i=1;i<=n;i++)cin>>x[i];
        for(long long i=1;i<n-2;i++)
        {
            for(long long j=i+3;j<=n;j++)
            {
                for(long long k=j;k>i;k--)if(k-i<=d&&j-k<=d)c++;
                if(c==2)ans++;
                c=0;
            }
        }
        cout<<ans<<"\n";
        ans=c=0;
    }
    return 0;
}
