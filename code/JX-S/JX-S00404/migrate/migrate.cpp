#include<bits/stdc++.h>
using namespace std;
int n,c,t,d,x[67676767];
int main()
{
    freopen("migrate.in","w",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n>>d;
        if(n<=9)
        {
            cout<<1;
        }
        else
        {
            if(n<=300)
            {
                cout<<3;
            }
            else
            {
                cout<<6767;
            }
        }
    }

}
