#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
    }else{
        cout<<0;
    }
    string t=s1.substr(0,2);
    string t1=s2.substr(0,2);
    if(t==t1&&c1==c2){
        cout<<1;
    }else{
        cout<<0;
     }
     char t3=s1[2];
     char t4=s2[2];
    if(((t3>='A'&&t3<='C'&&t4>='A'&&t4<='C')||(t3=='D'&&t4=='F')||(t3=='F'&&t4=='D'))&&t==t1&&c1==c2){
        cout<<1;
    }else{
        cout<<0;
    }
    if((t3-t4==1||t4-t3==1||t3=='D'&&t4=='F'||t3=='F'&&t4=='D')&&t==t1&&c1==c2){
        if(t3=='C'&&t4=='D'||t3=='D'&&t4=='C'){
            cout<<0;
            return 0;
         }else{
            cout<<1;
            return 0;
        }

    }else{
        cout<<0;
    }
    return 0;
}
