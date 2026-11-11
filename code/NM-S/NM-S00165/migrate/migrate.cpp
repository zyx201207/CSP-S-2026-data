#include<bits/stdc++.h>
using namespace std;
long long x[2000020];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long c=0,t=0;
    cin>>c>>t;
    while(t)
    {
        long long n,d;
        cin>>n>>d;
        for(int i=0;i<n;i++)
        {
            cin>>x[i];
        }
        t--;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
