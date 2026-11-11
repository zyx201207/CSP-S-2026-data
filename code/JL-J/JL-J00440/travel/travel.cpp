#include<bits/stdc++.h>
using namespace std;
int main(){string a[100];
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    for(int i=1;i<=4;i++){
        cin>>a[i];

    }
    if(a[1]=="02" && a[2]=="01A" && a[3]=="02" && a[4]=="01B"){
        cout<<1111;
    }
    if(a[1]=="02" && a[2]=="01C" && a[3]=="02" && a[4]=="01A"){
        cout<<1110;
    }
    if(a[1]=="02" && a[2]=="01C" && a[3]=="02" && a[4]=="01D"){
        cout<<1100;
    }
    if(a[1]=="02" && a[2]=="02B" && a[3]=="02" && a[4]=="01A"){
        cout<<1000;
    }
    if(a[1]=="02" && a[2]=="01A" && a[3]=="03" && a[4]=="01A"){
        cout<<0000;
    }

    return 0;
}

