#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a1,b1;
    string a2,b2;
    cin>>a1>>a2>>b1>>b2;
    if(a1==b1){
        cout<<"";
    }
    else{
        cout<<"0000";
        return 0;
    }
    if(a2[1]==b2[1] and a2[0]==b2[0]){
        cout<<"";
    }
    else{
        cout<<"1000";
        return 0;
    }
    if(a2[2]=='F' and b2[2]=='D' or a2[2]=='D' and b2[2]=='F'){
       cout<<"1111";
       return 0;
    }
    if(a2[2]=='F' and b2[2]=='A' or a2[2]=='F' and b2[2]=='B' or a2[2]=='F' and b2[2]=='C'){
        cout<<"1100";
        return 0;
    }
    if(a2[2]=='D' and b2[2]=='A' or a2[2]=='D' and b2[2]=='B' or a2[2]=='D' and b2[2]=='C'){
        cout<<"1100";
        return 0;
    }
    if(a2[2]=='A' and b2[2]=='F' or a2[2]=='B' and b2[2]=='F' or a2[2]=='C' and b2[2]=='F'){
        cout<<"1100";
        return 0;
    }
    if(a2[2]=='A' and b2[2]=='D' or a2[2]=='B' and b2[2]=='D' or a2[2]=='C' and b2[2]=='D'){
        cout<<"1100";
        return 0;
    }
    if(a2[2]=='A' and b2[2]=='B' or a2[2]=='A' and b2[2]=='B'){
        cout<<"1111";
        return 0;
    }
    if(a2[2]=='B' and b2[2]=='C' or a2[2]=='C' and b2[2]=='B'){
        cout<<"1111";
        return 0;
    }
    if(a2[2]=='A' and b2[2]=='C' or a2[2]=='C' and b2[2]=='A'){
        cout<<"1110";
        return 0;
    }
    return 0;
}
