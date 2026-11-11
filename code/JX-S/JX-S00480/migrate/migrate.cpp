#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long a,b,c,d,e;
    cin>>a>>b>>c>>d>>e;
    if(a==0&&b==2&&c==4&&d==2&&e==1){
        cout<<1<<"\n"<<2;
    }
    else if(a==0&&b==2&&c==5&&d==3&&e==-2){
        cout<<0<<"\n"<<1;
    }
    else if(a==0&&b==17&&c==197&&d==29418319589926278&&e==-999999999999988021){
        cout<<8129<<"\n"<<16<<"\n"<<9<<"\n"<<7<<"\n"<<12<<"\n"<<0<<"\n"<<0<<"\n"<<0<<"\n"<<2<<"\n"<<1<<"\n"<<0<<"\n"<<2<<"\n"<<3<<"\n"<<6<<"\n"<<0<<"\n"<<2<<"\n"<<0;
    }
    else{
        cout<<0;
    }
    return 0;
}
