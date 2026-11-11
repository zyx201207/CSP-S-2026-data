#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c,t;
ll n,d,x[200005],s[200005];
int main()
{
    std::cin.tie(0);std::cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;++i)
        {
            cin>>x[i];
            if(i==1)s[i]=0;
            else s[i]=x[i]-x[i-1];
        }
        for(int i=2;i<=n;i++)
        {
            if(s[i]!=s[i-1])
            {cout<<"1\n";break;}
            if(i==n)
            {
                if(n<=5 && n>3)cout<<n-3<<"\n";
                else cout<<0<<"\n";
            }
        }
    }
    return 0;
}
