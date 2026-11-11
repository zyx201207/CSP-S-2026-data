#include<bits/stdc++.h>
using namespace std;
long long x[1000001];
int main()
{
     freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long c,t;
    cin>>c>>t;
    while(t--)
    {
        long long n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
            cin>>x[i];
        long long delt=x[2]-x[1];
        long long ttt=0;
        if(d<2*delt)
            cout<<0<<"\n";
            else
        cout<<max(n-2*(d/delt)+1,ttt)<<"\n";
    }
}
