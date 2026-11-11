#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a1>>a2>>b1>>b2;
    if(a1==b1){
        cout<<"1";
    }else{
        cout<<"0";
    }

    if(a1==b1&&a2[0]==b2[0]&&a2[1]==b2[1]){
        cout<<"1";
    }else{
        cout<<"0";
    }

    int x,y;
    if(a2[2]>='A'&&a2[2]<='C'){
        x=1;
    }else{
        x=0;
    }
    if(b2[2]>='A'&&b2[2]<='C'){
        y=1;
    }else{
        y=0;
    }
    if(a1==b1&&a2[0]==b2[0]&&a2[1]==b2[1]&&x==y){
        cout<<"1";
        if(a1==b1&&a2[0]==b2[0]&&a2[1]==b2[1]&&(x==0&&y==0||!(a2[2]=='A'&&b2[2]=='C'||a2[2]=='C'&&b2[2]=='A'))){
            cout<<"1";
        }else{
            cout<<"0";
        }
    }else{
        cout<<"00";
    }

    return 0;
}
