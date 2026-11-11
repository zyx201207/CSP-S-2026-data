#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long a[2000200];
long long b[2000200];
long long temp[5050][5050];
pair<long long,long long> temp1[5050][5050];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        long long n,d,ans=0,cnt=0;
        cin>>n>>d;
        for(long long i=1;i<=n;i++) cin>>a[i];
        sort(a+1,a+n+1);
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                if(abs(a[i]-a[i-1])<=d)
                {
                    temp[i-1][i]=1;
                    temp1[1][++cnt]={i-1,i};
                }
                else
                {
                    break;
                }
            }
        }
        for(long long i=1;i<=n;i++)
        {
            long long minn;
            for(long long j=i;j<=n;j++)
            {
                if((a[j]-a[i])%d==0) minn=(a[j]-a[i])/2;
                else minn=(a[j]-a[i])/2+1;
                if(minn==1) continue;
                if(j-i-1==2)
                {
                    ans++;
                    continue;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
