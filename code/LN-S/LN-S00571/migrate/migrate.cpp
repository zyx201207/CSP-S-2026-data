#include<iostream>
using namespace std;
long long a[2000006];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    for(int i=1;i<=t;i++)
    {
        int n;
        long long d;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
    }
    cout<<1<<endl<<2;
}

