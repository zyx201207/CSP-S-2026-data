#include<bits/stdc++.h>
using namespace std;
string a1,b1,a2,b2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a1>>b1>>a2>>b2;
    int flag=1;
    if(a1==a2){
        cout<<"1";
    }
    else{
        cout<<"0";
        flag=0;
    }
    if(b1[0]==b2[0]&&b1[1]==b2[1]&&flag==1){
        cout<<"1";
    }
    else{
        cout<<"0";
        flag=0;
    }
    if(b1[2]=='A'||b1[2]=='B'||b1[2]=='C'){
        if((b2[2]=='A'||b2[2]=='B'||b2[2]=='C')&&flag==1){
            cout<<"1";
        }
        else{
            cout<<"0";
            flag=0;
        }
    }
    else if(b1[2]=='D'||b1[2]=='F'){
        if((b2[2]=='D'||b2[2]=='F')&&flag==1){
            cout<<"1";
        }
        else{
            cout<<"0";
            flag=0;
        }
    }
    if(abs(b1[2]-b2[2])==1&&flag==1){
        cout<<"1"<<endl;
    }
    else cout<<"0"<<endl;
    return 0;
}
