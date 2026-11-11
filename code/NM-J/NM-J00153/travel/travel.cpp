#include <bits/stdc++.h>
using namespace std;

int main (){
    int s=1;
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1[2],c2[2];
    char s1[3],s2[3];
    for(int i=1;i<=2;i++) cin >>c1[i];
    for(int i=1;i<=3;i++) cin >>s1[i];
    for(int i=1;i<=2;i++) cin >>c2[i];
    for(int i=1;i<=3;i++) cin >>s2[i];
    cout <<s;
    for(int i=1;i<=2;i++){
        if(c1==c2) {
            s=2;
        }else { s=1;}
    }
    if(s==2){
        cout <<"1";
    }else{
    cout <<"0000";
    return 0;
    }
    s=1;
     for(int i=1;i<=2;i++){
        if(s1[i]==s2[i]){
            s=2;
        }else{
        s=1;
        }
     }
     if(s==2){
        cout <<"1";
     }else{
     cout <<"000";
     return 0;
     }
     s=1;
     if(s1[3]=='D'&&s1[3]=='F'||s1[3]=='F'&&s2[3]=='D'||s1[3]=='A'&&s2[3]=='B'){
        cout <<"11";
     }else{cout <<"10";}
}
