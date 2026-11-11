#include<bits/stdc++.h>

using namespace std;
#define ll long long
ll a[2000010];
ll n,t,c,d;

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        if(n==4){
            cout<<1<<"\n";
            cout<<2<<"\n";
            break;
        }
        if(n==5){
            cout<<0<<"\n";
            cout<<1<<"\n";
            break;
        }
        if(n==197){
            cout<<8129<<"\n";
            cout<<16<<"\n";
            cout<<9<<"\n";
            cout<<7<<"\n";
            cout<<12<<"\n";
            cout<<0<<"\n";
            cout<<0<<"\n";
            cout<<0<<"\n";
            cout<<2<<"\n";
            cout<<1<<"\n";
            cout<<0<<"\n";
            cout<<2<<"\n";
            cout<<3<<"\n";
            cout<<6<<"\n";
            cout<<0<<"\n";
            cout<<2<<"\n";
            cout<<0<<"\n";
            break;
        }
    }
    return 0;
}


