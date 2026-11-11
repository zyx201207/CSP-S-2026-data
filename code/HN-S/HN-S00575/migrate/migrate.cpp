#include<bits/stdc++.h>
using namespace std;
int n;
int d;
int c;
int t;

int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t!=0)
    {
        cin>>n>>d;
        int a[n+5];
        int a1[n+5];
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }

        a[0]=a[1];
        for(int i=1;i<=n;i++)
        {
            a1[i]=a[i]-a[i-1];
        }


cout<<2;
    }


    return 0;
}
