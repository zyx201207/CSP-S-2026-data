#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1;
    string c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<"1";
    }
    else{
        cout<<"0000";
        return 0;
    }
    if(s1.substr(0,2)==s2.substr(0,2)){
        cout<<"1";
    }
    else{
        cout<<"000";
        return 0;
    }
    char q1=s1[2],q2=s2[2];
    if(q1=='A' || q1=='B' || q1=='C'){
        if(q2=='D' || q2=='F'){
            cout<<"00";
            return 0;
        }
        else{
            cout<<"1";
        }
    }
    else if(q1=='D' || q2=='F'){
        if(q2=='A' || q2=='B' || q2=='C'){
            cout<<"00";
            return 0;
        }
        else{
            cout<<"11";
            return 0;
        }
    }
    if(q1=='A' || q1=='B' || q1=='C'){
        if((q2-q1==1) || (q1-q2==1)){
            cout<<"1";
        }
        else{
            cout<<"0";
        }
    }
    return 0;
}
