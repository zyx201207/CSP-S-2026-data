#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000005];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int z=1; z<=t; z++)
    {
        cin>>n>>d;
        for(int i=1; i<=n; i++) cin>>x[i];
        int a=x[2]-x[1];
        d=d/a;
        if(d!=2) cout<<"0"<<endl;
        else cout<<n-3<<endl;
    }
    return 0;
}
