#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int s=0;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
        s++;
    }else{
        cout<<0;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1]&&s==1){
        cout<<1;
        s++;
    }
    else{
        cout<<0;
    }
    if((s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')){
        if(s==2){
            cout<<1;
            s++;
        }else{
            cout<<0;
        }
    }else{
        cout<<0;
    }
    if((s1[2]+1==s2[2]||s1[2]==s2[2]+1)&&s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C'){
        if(s==3){
            cout<<1;
        }else{
            cout<<0;
        }
    }else if((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')){
        if(s==3){
            cout<<1;
        }else{
            cout<<0;
        }
    }
    else{
        cout<<0;
    }
    return 0;
}
