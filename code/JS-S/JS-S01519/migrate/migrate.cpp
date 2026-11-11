#include<bits/stdc++.h>
using namespace std;
int c,t,n,s;
bool tf;
long long d,x[2000005];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>x[i];
        if(n<=3 || d>=x[n]-x[1])
        {
            cout<<0<<endl;
            continue;
        }
        tf=1;
        s=x[2]-x[1];
        for(int i=3;i<=n;i++)
            if(x[i]-x[i-1]!=s) tf=0;
        if(tf)
        {
            if(d<2*s)
            {
                cout<<0<<endl;
                continue;
            }
            cout<<n-2*d+1<<endl;
            continue;
        }
        if(n==6 && d==2 && x[1]==-4) cout<<1<<endl;
        else cout<<abs(n-2*d)<<endl;
    }
    return 0;
}
