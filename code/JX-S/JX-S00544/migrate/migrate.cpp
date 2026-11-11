#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d,x[2000001]={},ans;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n>>d;
        for(int j=1;j<=n;j++)
        {
            cin>>x[j];
        }
        ans=0;
        for(int j=1;j<=n;j++)
        {
            for(int k=j+1;k<=n;k++)
            {
                if(x[k]-x[j]>d&&k-j+1>=d*2&&x[k]-x[k-1]<=d&&x[k]-x[j]<2*d)
                {
                    ans++;
                }
                if(x[k]-x[k-1]>d)
                {
                    break;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
