#include<bits/stdc++.h>
using namespace std;
long long a[2000005];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,T;
    cin>>c>>T;
    while(T--)
    {
        long long n,d,ans=0;
        cin>>n>>d;

        for(int i=1;i<=n;i++) cin>>a[i];
        int f=1,judge=a[2]-a[1];
        for(int i=3;i<=n;i++)
        {
            if(a[i]-a[i-1]!=judge) f=0;
        }
        judge=abs(judge);
        d=d/judge*judge;
        if(a[1]!=1)
        {
            for(int i=1;i<=n;i++)
            {
                a[i]=a[i]-a[1]+1;
            }
        }

        if(judge!=1) for(int i=1;i<=n;i++) a[i]=(a[i]+judge-1)/judge;
 //       else {for(int i=1;i<=n;i++) a[i]=(a[i]+judge-1)/judge;}
        d/=judge;
        cout<<max(0LL,n-2*d+1)<<'\n';continue;//11 12
    }
    return 0;
}
