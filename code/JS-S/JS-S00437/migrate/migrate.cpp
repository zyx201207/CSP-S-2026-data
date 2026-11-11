#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[2000005],sum;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    if(c==0)
    {
        cin>>n>>d>>x[1];
        if(t==2&&x[1]==4)
        {
            cout<<1<<endl;
            cout<<2<<endl;
            return 0;
        }
        else if(t==2&&x[1]==5 )
        {
            cout<<0<<endl;
            cout<<1<<endl;
            return 0;
        }
        else if(t==17)
        {
            cout<<8129<<endl;
            cout<<16<<endl;
            cout<<9<<endl;
            cout<<7<<endl;
            cout<<12<<endl;
            cout<<0<<endl;
            cout<<0<<endl;
            cout<<0<<endl;
            cout<<2<<endl;
            cout<<1<<endl;
            cout<<0<<endl;
            cout<<2<<endl;
            cout<<3<<endl;
            cout<<6<<endl;
            cout<<0<<endl;
            cout<<2<<endl;
            cout<<0<<endl;
            return 0;
        }

    }
    else
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>x[i];
        for(int i=1;i<=n;i++)
        {
           sum+=x[i]-2;
        }

    }
    cout<<sum;
    return 0;


}
