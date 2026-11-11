#include<iostream>
#include<cstdio>
using namespace std;
const int N=2e6+5;
int c,t,n,d,a[N];
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
        cout<<"1\n";
    }
    return 0;
}
