#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c,t,ans;
ll x[2000005],s;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        ans=0;
        int n;
        ll d;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>x[i];
        }
        s=x[2]-x[1];
        ll a=d/s;
        for(int i=a+1;i*s<d*2;i++)
        {
            ll l=i*s;
            if(l>(a-1)*s*2)
            {
                ans+=n-i;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

