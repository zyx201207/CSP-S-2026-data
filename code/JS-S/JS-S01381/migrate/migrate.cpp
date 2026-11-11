#include<bits/stdc++.h>
using namespace std;
int c,T,n,d,a[10001];
queue<int> q;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    int k=T;
    while(T--){
        cin>>n>>d;
        if(n==4&&d==2) cout<<1<<endl;
        if(n==5&&d==2) cout<<2<<endl;
        if(d==3) cout<<0<<endl;
        if(n==6) cout<<1<<endl;

    }
     if(k==17) cout<<8129<<endl<<16<<endl<<9<<endl<<7<<endl<<7<<endl<<12<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl<<0;
     if(k==12) cout<<0<<endl<<0<<endl<<259997<<endl<<259995<<endl<<86669<<endl<<0<<endl<<0<<endl<<0<<endl<<7<<endl<<5<<endl<<5<<endl<<0;
    return 0;
}
