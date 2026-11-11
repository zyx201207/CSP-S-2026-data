#include<iostream>
#include<cmath>
using namespace std;

string c1,s1,c2,s2;

bool judge(){
    char a=s1[2],b=s2[2];
    bool b1,b2;
    if(a=='A'||a=='B'||a=='C'){
        b1=true;
    }else{
        b1=false;
    }
    if(b=='A'||b=='B'||b=='C'){
        b2 = true;
    }else{
        b2 = false;
    }
    if(b1==b2){
        return true;
    }
    return false;

}

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    cin >> c1 >> s1 >> c2 >> s2;
    bool isInSame;
    if(c1==c2){
        cout << 1;
    }else{
        cout << "0000";
        return 0;
    }
    if(s1[0]==s2[0] && s1[1]==s2[1]){
        cout << 1;
    }else{
        cout << "000";
        return 0;
    }
    isInSame=judge();
    if(isInSame){
        cout << 1;
    }else{
        cout << "00";
        return 0;
    }
    if(abs(int(s1[2]-s2[2]))==1){
        cout << 1;
    }else{
        cout << 0;
    }
    return 0;

}
