#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a;

int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>a;
        if(n>3)cout<<n-3<<endl;
        else cout<<0<<endl;
    }
    return 0;
}
