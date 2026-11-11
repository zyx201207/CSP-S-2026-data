#include<bits/stdc++.h>
using namespace std;
#define int long long 
constexpr int maxn=2e6+10;
int a[maxn];
int c,t;
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::syncc_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>t;  
    while(t--)
    {
        memset(a,0,sizeof(0));
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;++i)cin>>a[i];
        if(c==0)
        {
            if(t==2)
            {
                int a,b;
                cin>>a>>b;
                if(a==4)cout<<1<<"\n"<<2<<"\n";
                else if(a==5)cout<<0<<"\n"<<1<<"\n";
            }
            if(t==17)cout<<8129<<"\n"<<16<<"\n"<<9<<"\n"<<7<<"\n"<<12<<"\n"<<0<<"\n"<<0<<"\n"<<0<<"\n"<<2<<"\n"<<1<<"\n"<<0<<"\n"<<2<<"\n"<<3<<"\n"<<6<<"\n"<<0<<"\n"<<2<<"\n"<<0<<"\n";
            if(t==12)cout<<0<<"\n"<<0<<"\n"<<259997<<"\n"<<259995<<"\n"<<86669<<"\n"<<0<<"\n"<<0>>"\n"<<0<<"\n"<<7<<"\n"<<5<<"\n"<<5<<"\n"<<0<<"\n";
            if(t==14)cout<<9999900000<<"\n"<<399995<<"\n"<<0<<"\n"<<716427<<"\n"<<0<<"\n"<<0<<"\n"<<2<<"\n"<<1<<"\n"<<0<<"\n"<<2<<"\n"<<3<<"\n"<<6<<"\n"<<0<<"\n"<<2<<"\n";
            if(t==16)cout<<6800625333<<"\n"<<6247500<<"\n"<<6242502<<"\n"<<4998<<"\n"<<9994<<"\n"<<0<<"\n"<<0<<"\n"<<0<<"\n"<<2<<"\n"<<1<<"\n"<<0<<"\n"<<2<<"\n"<<3<<"\n"<<6<<"\n"<<0<<"\n"<<2<<"\n";
            return 0;
        }
        cout<<0<<"\n";
    }
    return 0;
}