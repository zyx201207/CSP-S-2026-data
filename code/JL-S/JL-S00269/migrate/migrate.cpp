#include <bits/stdc++.h>
using namespace std;
long long int ans,n,d,a[2000005],s[2000005];
int main()
{
    int c,T;
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while(T--)
    {
        cin>>n>>d;
        for(long long i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        for(long long i=1;i<=n;i++)
        {
            s[i]=max(s[i-1],i);
            for(long long j=s[i-1];j<=n;j++)
            {
                if(a[j]-a[i]<=d)s[i]=j;
            }
        }
        ans=0;
        long long sgle=1,dble=0;
        bool flat=0;
        for(long long i=n;i>=1;i--)
        {
            if(s[i]==i+1)
            {
                sgle+=1;
            }
            if(s[i]<i+1)
            {

                ans+=dble*sgle;
                sgle=1;
                dble=0;
            }
            if(s[i]==i+2)
            {
                ans+=dble*sgle;
                dble=max(sgle-2,0LL);
                sgle=0;
            }
            if(s[i]>i+2)
            {
                ans+=dble*sgle;
                sgle=1,dble=0;
            }

        }
        ans+=dble*sgle;
        cout<<ans<<endl;
    }
    return 0;
}
