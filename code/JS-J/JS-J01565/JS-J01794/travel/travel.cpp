#include <bits/stdc++.h>
using namespace std;
int tq(string s){
    int c=0;
    for(int i=0;i<s.size();i++){
        if(isdigit(s[i])){
            c=c*10+(s[i]-'0');
        }
    }
    return c;
}
bool check(char a,char b){
    if((a>='A'&&a<='C'&&b<='C'&&b>='A')||((a=='D'||a=='F')&&(b<='D'&&b>='A'))){
        return 1;
    }
    return 0;
}
bool check1(char a,char b){
    if(abs(a-b)==1||((a=='D'&&b=='F')||(a=='F'&&b=='D'))){
        return 1;
    }
    return 0;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,c3,c4;
    cin>>c1>>c2>>c3>>c4;
    if(tq(c1)==tq(c3)){
        cout<<"1";
        if(tq(c2)==tq(c4)){
            cout<<"1";
            char a1=c2[c2.size()-1],b1=c4[c4.size()-1];
            if(check(a1,b1)){
                cout<<"1";
                if(check1(a1,b1)){
                    cout<<"1";
                }else{
                    cout<<"0";
                }
            }else{
                cout<<"00";
            }
        }else{
            cout<<"000";
        }
    }else{
        cout<<"0000";
    }
    return 0;
}
