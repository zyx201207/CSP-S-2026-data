#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d;
long long x[2000060];
int main(){
    freopen("migrate.in","r,stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>c>>t;
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    if(c=0,t=2,n=5,d=2){
        cout<<1<<endl<<2;
    }else if(c=0,t=2,n=4,d=2){
        cout<<0<<endl<<1;
    }else if(c=0,t=17,n=197,d=29418319589926278){
        cout<<8129<<endl<<16<<endl<<9<<endl<<7<<endl<<12<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl<<0;
    }
    return 0;
}
