#include<bits/stdc++.h>
using namespace std;
int c,z,t,f,x[2000010],y[2000010];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    z=t;
    while(t--)
    {
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>x[i];
            if(t==z-1)
            {
                y[i]=x[i];
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(y[i]>=0)
            {
                cout<<y[i+f]<<endl;
                f++;
                break;
            }
        }
    }
    return 0;
}
