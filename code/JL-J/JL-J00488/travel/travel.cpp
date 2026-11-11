#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b;
    string s1,s2;
    cin>>a;
    for(int i=0;i<3;i++){
        cin>>s1[i];
    }
    cin>>b;
    for(int i=0;i<3;i++){
        cin>>s2[i];
    }
    bool f=0;
    if(a==b){
        cout<<"1";
    }else{
        cout<<"0";
        f=1;
    }
    if(f=1){
        cout<<"000";
        return 0;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1]){
        cout<<"1";
    }else{
        cout<<"0";
        f=1;
    }
    if(f=1){
        cout<<"00";
        return 0;
    }
    if(s1[2]<='C'&&s2[2]<='C'){
        cout<<"1";
    }else if(s1[2]>='D'&&s2[2]>='D'){
        cout<<"1"<<"1";
        return 0;
    }else{
        cout<<"0";
        f=1;
    }
    if(f=1){
        cout<<"0";
        return 0;
    }
    if(s2[2]+1==s1[2]||s2[2]-1==s1[2]){
        cout<<"1";
    }else{
        cout<<"0";
    }
    return 0;
}
