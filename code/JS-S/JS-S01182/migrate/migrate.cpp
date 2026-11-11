#include<bits/stdc++.h>
using namespace std;
constexpr int N=2e6+5;
int n,c,t;
long long d,a[N];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;

        for(int i=1;i<=n;i++)
            cin>>a[i];
        long long dm=a[2]-a[1];
        if(dm>=d)
        {
            cout<<0<<"\n";
            break;
        }
        else
        {
            long long k=d/dm;
            k=k*2-1;
            cout<<n-k+<<"\n";
            break;
        }
    }
    return 0;
}
