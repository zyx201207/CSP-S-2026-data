#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,T;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while(T--)
    {
        int ans=0;
        int n;
        ll d;
        cin>>n>>d;
        vector<ll> a(n+1);
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<=n-3;i++)
            if(a[i+2]==a[i]+d&&a[i+3]==a[i+1]+d) ans++;
        cout<<ans<<endl;
    }
    return 0;
}
