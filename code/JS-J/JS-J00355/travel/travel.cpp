#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,r1,c2,r2;
    cin>>c1>>r1>>c2>>r2;
    if(c1!=c2){
        cout<<"0000"<<endl;
        return 0;
    }
    string p1=r1.substr(0,2);
    string p2=r2.substr(0,2);
    if(p1!=p2){
        cout<<"1000"<<endl;
        return 0;
    }
    if(r1[2]<='C'&&r2[2]>='D'||
       r2[2]<='C'&&r1[2]>='D'){
        cout<<"1100"<<endl;
        return 0;
    }
    if((r1[2]=='D'&&r2[2]=='F')||
        (r1[2]=='F'&&r2[2]=='D')||
        (abs(r2[2]-r1[2])==1)){
        cout<<"1111"<<endl;
        return 0;
    }
    else{
        cout<<"1110"<<endl;
    }
    return 0;
}