#include<bits/stdc++.h>
using namespace std;
bool check1(string c1,string c2){
    if(c1==c2)return true;
    return false;
}
bool check2(string s1,string s2){
    if(s1[0]+s1[1]==s2[0]+s2[1])return true;
    return false;
}
bool check3(string s1,string s2){
    if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
        if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
            return true;
        }
    }
    if(s1[2]=='D'||s1[2]=='F'){
        if(s2[2]=='D'||s2[2]=='F'){
            return true;
        }
    }
    return false;
}
bool check4(string s1,string s2){
    if(abs((s1[2]-'A')-(s2[2]-'A'))==1){
        if(s1[2]=='C'&&s2[2]=='D'){
            return false;
        }
        return true;
    }
    return false;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(check1(c1,c2)){
        cout<<1;
        if(check2(s1,s2)){
            cout<<1;
            if(check3(s1,s2)){
                cout<<1;
                if(check4(s1,s2)){
                    cout<<1;
                }
                else{
                    cout<<"0";
                }
            }
            else{
                cout<<"00";
            }
        }
        else{
            cout<<"000";
        }
    }
    else{
        cout<<"0000";
    }
    return 0;
}
