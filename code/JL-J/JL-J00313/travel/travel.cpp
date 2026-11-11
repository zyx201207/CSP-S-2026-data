#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,k,f,d;
    cin >> a >> k >> f >> d;
    if(a==f){
        cout << '1';
    }
    else{
        cout << "0000";
        return 0;
    }
    string z="",w="";
    z+=k[0]+k[1];
    w+=d[0]+d[1];
    if(z==w){
        cout << '1';
    }
    else{
        cout << "000";
        return 0;
    }
    if((k[2]>='A'&&k[2]<='C'&d[2]>='A'&&d[2]<='C')||(k[2]>='D'&&k[2]<='F'&&d[2]>='D'&&d[2]<='F')){
        cout << '1';
    }
    else{
        cout << "00";
        return 0;
    }
    if((k[2]=='A'&&d[2]=='B')||(k[2]=='B'&&d[2]=='C')||(k[2]=='D'&&d[2]=='F')){
        cout << '1';
    }
    else{
        cout << '0';
    }
    return 0;
}
