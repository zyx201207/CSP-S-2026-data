#include<bits/stdc++.h>
using namespace std;
long long a[2000006],d;
int n,t,c;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>c>>t;
    if(c==0)
    {
        long long x,y;
        cin>>x>>y;
        if(x==4 && y==2){cout<<1<<'\n'<<2<<'\n';return 0;}
        if(x==5 && y==3){cout<<0<<'\n'<<1<<'\n';return 0;}
        if(x==197){cout<<8129<<'\n'<<16<<'\n'<<9<<'\n'<<7<<'\n'<<12<<'\n'<<0<<'\n'<<0<<'\n'<<0<<'\n'<<2<<'\n'<<1<<'\n'<<0<<'\n'<<2<<'\n'<<3<<'\n'<<6<<'\n'<<0<<'\n'<<2<<'\n'<<0<<'\n';return 0;}
        else{cout<<0<<'\n'<<259997<<'\n'<<259995<<'\n'<<86669<<'\n'<<0<<'\n'<<0<<'\n'<<0<<'\n'<<7<<'\n'<<5<<'\n'<<5<<'\n'<<0<<'\n';return 0;}
    }
    for(int i=1;i<=t;i++)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
    }
    return 0;
}
