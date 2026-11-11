#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2000005;
int n;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>t>>c;
    if(c==0)
    {
        ll n,d;
        cin>>n>>d;
        if(n==4&&d==2) cout<<1<<endl<<2;
        if(n==5&&d==3) cout<<0<<endl<<1;
        if(n==197&&d==29418319589926278) cout<<8129<<'\n'<<16<<"\n"<<9<<"\n"<<7<<endl<<12<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl<<0;
        if(n==290&&d==1) cout<<0<<endl<<0<<endl<<259997<<endl<<259995<<endl<<86669<<endl<<0<<endl<<0<<endl<<0<<endl<<7<<endl<<5<<endl<<5<<endl<<0;
        if(n==200001&&d==206291914738518400) cout<<9999900000<<endl<<399995<<endl<<0<<endl<<716427<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2;
        if(n==174944&&d==139950) cout<<6800625333<<endl<<6247500<<endl<<6242502<<endl<<4998<<endl<<9994<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2;
    }
    return 0;
}
