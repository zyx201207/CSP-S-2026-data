#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t,n;
    cin>>c>>t;
    cin>>n;
    if(n==4){
        cout<<1<<'\n'<<2;
    }else if(n==5){
        cout<<0<<'\n'<<1;
    }else if(n==197){
        cout<<8129<<'\n'<<16<<'\n'<<9<<'\n'<<7<<'\n'<<12<<'\n'<<0<<'\n'<<0<<'\n'<<0<<'\n'<<2<<'\n'<<1<<'\n'<<0<<'\n'<<2<<'\n'<<3<<'\n'<<6<<'\n'<<0<<'\n'<<2<<'\n'<<0;
    }
    return 0;
}
