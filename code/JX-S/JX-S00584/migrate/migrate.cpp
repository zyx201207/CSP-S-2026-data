#include<bits/stdc++.h>
using namespace std;
int c,t,x[2000100];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>x[i];
        }
        if(abs(x[n]-x[1])<d)
        {
            cout<<0<<endl;
            return 0;
        }
        if(n<=3)
        {
            cout<<0<<endl;
            continue;
        }
        if(n==4)
        {
            if(abs(x[3]-x[1])<=d&&abs(x[4]-x[2])<=d)
            {
                cout<<1<<endl;
                continue;
            }
            cout<<0<<endl;
            continue;
        }
        if(n==5)
        {
            int t=0;
            if(abs(x[3]-x[1])<=d&&abs(x[4]-x[2])<=d&&abs(x[4]-x[1])>d)
            {
                t++;
            }
            if(abs(x[4]-x[2])<=d&&abs(x[5]-x[3])<=d&&abs(x[5]-x[2])>d)
            {
                t++;
            }
            if((abs(x[3]-x[1])<=d&&abs(x[5]-x[3])<=d)&&((abs(x[4]-x[1])>d&&abs(x[5]-x[2])<=d)||(abs(x[4]-x[1])<=d&&abs(x[5]-x[2])>d)))
            {
                t++;
            }
            cout<<t;
            continue;
        }
    }
    return 0;
}
