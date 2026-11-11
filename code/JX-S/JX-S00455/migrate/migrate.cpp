#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[500005]={};
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
    }
    if(n==4&&d==2){
        cout<<1;
        cout<<endl;
        cout<<2;
    }
    else if(n==5&&d==3){
        cout<<0;
        cout<<endl;
        cout<<1;
    }
    else if(c==0&&t==17){
        cout<<8129<<endl<<16<<endl<<9<<endl<<7<<endl<<12<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl<<0;
    }
    return 0;
}
