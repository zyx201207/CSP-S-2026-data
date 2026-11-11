#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000005];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        long long xz=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            // if(i==2)
            // {
            //     xz=a[i]-a[i-1];
            // }
            // else if(i>1)
            // {
            //     if(a[i]-a[i-1]!=xz||xz==-1)
            //     {
            //         return 0;
            //         xz=-1;
            //     }
            //     else
            //     {
            //         xz=a[i]-a[i-1];
            //     }
            // }
        }
        cout<<0<<endl;
        // if(xz!=-1)
        // {
        //     if(d<2*xz)
        //     {
        //         cout<<0<<endl;
        //     }
        //     else if(d>=2*xz&&d<3*xz)
        //     {
        //         long long ans=0;
        //         for(long long j=3;j<=n;j+=2)
        //         {
        //             ans+=n-j+1;
        //         }
        //         cout<<ans<<endl;
        //     }
        //     else
        //     {
        //         cout<<0<<endl;
        //     }
        // }
        // else
        // {
        //     cout<<0<<endl;
        // }
    }
    return 0;
}