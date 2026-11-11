#include<bits/stdc++.h>
using namespace std;
struct a{
    int c;
    string z;
};
int main(){
    freopen("travel.in","w",stdin);
    freopen("travel.out","r",stdout);
    a a1,a2;
    cin>>a1.c>>a1.z>>a2.c>>a2.z;
    if(a1.c==a2.c){
        cout<<"1";
        if(a1.z[0]==a2.z[0]&&a1.z[1]==a2.z[1]){
            cout<<"1";
            if(((a1.z[2]>='A'&&a1.z[2]<='C')&&(a2.z[2]>='A'&&a2.z[2]<='C'))||((a1.z[2]=='D'&&a2.z[1]=='F')||(a2.z[2]=='D'&&a1.z[1]=='F'))){
        cout<<"1";
         if((a1.z[2]==a2.z[2]+1||a1.z[2]==a2.z[2]-1)||((a1.z[2]=='D'&&a2.z[1]=='F')||(a2.z[2]=='D'&&a1.z[1]=='F'))){
        cout<<"1";

    }else{
        cout<<"0";
    }
    }else{
        cout<<"00";
    }
        }else{
            cout<<"000";
        }
    }else{
        cout<<"0000";
    }


    return 0;
}
