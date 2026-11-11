#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long n,x,d,a[200001],k,sum=0;
    cin>>n;
    if(n>=11&&n<=12)
    {
        cin>>n;
        while(n--)
        {
            cin>>x>>d;
            sum=0;
            for(int i=1;i<=x;i++)
            {
                cin>>a[i];
            }
            k=a[2]-a[1];
            if(d/k<2)
            {
                cout<<0<<endl;
                continue;
            }
            else
            {
                int m=x-3;
                for(int i=1;i<=d/k-1;i++)
                    sum+=m,m--;
            }
            cout<<sum<<endl;
        }
    }
    return 0;
}
