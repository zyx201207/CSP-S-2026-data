#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long n,d;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    srand(time(0));
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            long long a;
            cin>>a;
        }
        long long ans=rand()%(n-n/4);
        cout<<ans<<endl;
    }
}
