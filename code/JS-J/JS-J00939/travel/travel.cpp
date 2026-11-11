//2026/10/31 9:01 probaly 100pts
#include <bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4;

bool check(char a,char b){
    if(abs(int(a)-int(b))==1){
        if((a=='C'&&b=='D')||(a=='D'||b=='C')){
            return 0;
        }else{
            return 1;
        }
    }else{
        return 0;
    }
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>c2>>c3>>c4;
    if(c1==c3){
        cout<<"1";
    }else{
        cout<<"0000";
        return 0;
    }//step1
    if(c2[0]==c4[0]&&c2[1]==c4[1]){
        cout<<"1";
    }else{
        cout<<"000";
        return 0;
    }//step2;
    cout<<(c2[0]==c4[0] && c2[1]==c4[1])<<endl;
    if((c2[2]<='C'&&c4[2]<='C')||(c2[2]>='D'&&c4[2]>='D')){
        cout<<1;
    }else{
        cout<<"00";
        return 0;
    }//step3
    if(check(c2[2],c4[2])){
        cout<<"1";
    }else{
        cout<<"0";
    }
    return 0;
}
