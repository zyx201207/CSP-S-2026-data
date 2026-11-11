#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,sz1="",sz2="";
int pd1,pd2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<"1";
    }
    else{
        cout<<"0000";
        return 0;
    }
    for(int i=0;i<2;i++){
        sz1+=s1[i];
        sz2+=s2[i];
    }
    if(sz1==sz2){
        cout<<"1";
    }
    else{
        cout<<"000";
        return 0;
    }
    if(s1[2]>='A'&&s1[2]<='C'){
        pd1=1;
    }
    if(s2[2]>='A'&&s2[2]<='C'){
        pd2=1;
    }
    if(pd1==pd2){
        cout<<"1";
    }
    else{
        cout<<"00";
        return 0;
    }
    if(pd1==0&&pd2==0){
        cout<<"1";
        return 0;
    }
    if(abs(int(s1[2]-s2[2]))==1){
        cout<<"1";
    }
    else{
        cout<<"0";
    }
    return 0;
}
