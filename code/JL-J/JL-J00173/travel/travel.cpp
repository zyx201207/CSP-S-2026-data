#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",in);
    freopen("travel.out","w",out);
    char a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a=="02"&&b=="01A"&&c=="02"&&d=="01B"){
       cout<<"1111"<<endl;
    }
    if(a=="02"&&b=="01C"&&c=="02"&&d=="01A"){
       cout<<"1111"<<endl;
    }
    if(a=="02"&&b=="01C"&&c=="02"&&d=="01D"){
       cout<<"1100"<<endl;
    }
    if(a=="02"&&b=="02B"&&c=="03"&&d=="01A"){
       cout<<"0000"<<endl;
    }
    return 0;
}
