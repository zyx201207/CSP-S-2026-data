#include<bits/stdc++.h>
using namespace std;
long long c,t,d,n,Y=0;
long long x[100000100],dp[10000100];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    cin>>n>>d;
    for(int i=1;i<=n;i++)
    {
        cin>>x[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=2;j<=n+1;j++)
        {
            if(x[j]-x[i]<=d)
            {
                x[i]=x[j];
                Y++;
            }
        }
    }
    cout<<Y;
    return 0;
}