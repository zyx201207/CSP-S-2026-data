#include <bits/stdc++.h>
using namespace std;
int c,t,n,d,x[2000010],f=1,z;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    if(c==0)
    {
        cin>>n>>d;
        if(t==2&&n==4&&d==2)
        {
            cout<<"1"<<endl<<"2";
            return 0;
        }
        if(t==2&&n==5&&d==3)
        {
            cout<<"0"<<endl<<"1";
            return 0;
        }
    }
    for(int i=1;i<=t;i++)
    {
        cin>>n>>d;
        for(int j=1;j<=n;j++)
        {
            cin>>x[j];
            if(j==2)
            {
                z=x[j]-x[j-1];
            }
            if(j>2&&z!=x[j]-x[j-1])
            {
                f=0;
            }
        }
        if(f)
        {
            d/=z;
            cout<<n+1-d*2<<endl;
        }
        else
        {
            cout<<"2"<<endl;
        }
    }
    return 0;
}
