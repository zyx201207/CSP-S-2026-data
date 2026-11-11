#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    bool f1=1;
    for(int i=0;i<c1.size();i++){
        if(c1[i]!=c2[i]){
            cout<<"0";
            f1=0;
            break;
        }
    }
    if(f1){
        cout<<"1";
    }
    bool f2=1;
    if(f1){
        for(int i=0;i<2;i++){
            if(s1[i]!=s2[i]){
                f2=0;
                break;
            }
        }
    }
    else{
        f2=0;
    }
    if(f2){
        cout<<"1";
    }
    else{
        cout<<"0";
    }
    bool f3=1;
    if(f2){
        if(s1[2]<='C'&&s2[2]>='D'){
            f3=0;
        }
        if(s2[2]<='C'&&s1[2]>='D'){
            f3=0;
        }
    }
    else{
        f3=0;
    }
    if(f3){
        cout<<"1";
    }
    else{
        cout<<"0";
    }
    if(f3){
        if(s1[2]=='A'&&s2[2]=='C'){
            f4=0;
        }
        if(s2[2]=='A'&&s1[2]=='C'){
            f4=0;
        }
    }
    else{
        f4=0;
    }
    if(f4){
        cout<<"1";
    }
    else{
        cout<<"0";
    }
    return 0;
}