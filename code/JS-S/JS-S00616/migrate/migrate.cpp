#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long arr[20000006];
long long cd[20000006];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>t;
    for(long long u=1;u<=t;u++)
    {
        long long sum=0;
        long long n,d;
        cin>>n>>d;
        for(long long i=1;i<=n;i++)
        {
            cin>>arr[i];
            cd[i]=0;
        }
        for(long long i=1;i<=n;i++)
        {
            long long r=arr[i]+d;
            long long a=-1,b=-1;
            long long o=0;
            for(long long j=i+1;j<=n;j++)
            {
                if(r<arr[j])
                    break;
                if(a==-1)
                a=j;
                else if(b==-1)
                {

                    b=j;
                    o=1;
                }
                else
                {
                    o=0;
                    break;
                }
            }
            if(a!=-1&&b==-1)
                cd[i]=a;
            if(o)
            {
                long long l1=arr[a]+d;
                long long l2=arr[b]+d;
                for(long long j=i+3;j<=n;j++)
                {if(l1<arr[j]||l2<arr[j])
                       break;

                     sum++;

                }

            }

        }cout<<sum<<endl;
    }
    return 0;
}
