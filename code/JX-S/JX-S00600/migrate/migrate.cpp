#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int C,T;
    cin>>C>>T;
    while(T--)
    {
        int n;
        long long d;
        cin>>n>>d;
        long long x[2000005];
        for(int i=1;i<=n;i++)
            cin>>x[i];
        int ch=x[2]-x[1];
        cout<<n;
    }
    return 0;
}
