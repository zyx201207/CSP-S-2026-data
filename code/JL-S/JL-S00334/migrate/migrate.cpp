#include<bits/stdc++.h>
using namespace std;
long long xx[2000005];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    for(int i=1;i<=t;i++)
    {
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>xx[i];
        }
        if(xx[n]-xx[n-1]==xx[n-1]-xx[n-2])
        {
            cout<<0<<endl;
        }
        else
        {
            cout<<xx[n]-xx[n]<<endl;
        }
    }
    return 0;
}
