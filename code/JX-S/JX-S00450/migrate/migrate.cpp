#include <bits/stdc++.h>
using namespace std;
int c,t;
int n;
long long d;
long long x[2000005];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n>>d;
        long long maxx,minx;
        cin>>x[1];
        maxx=x[1];
        minx=x[1];
        for(int j=2;j<=n;j++)
        {
            cin>>x[j];
            maxx=max(maxx,x[j]);
            minx=min(minx,x[j]);
        }
        if(max(x[1],x[2])-min(x[1],x[2])<=2*d)
        {
            cout<<(n-1)*(n-2)/2<<"\n";
            continue;
        }
        sort(x+1,x+1+n);
        if(maxx-minx<=2*d)
            cout<<n-3<<"\n";
    }
    return 0;
}
