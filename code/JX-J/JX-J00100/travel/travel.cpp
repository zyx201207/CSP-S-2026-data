#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool check(char a,char b){
    bool flag1=false,flag2=false;
    if(a=='A'||a=='B'||a=='C'){
        flag1=true;
    }
    if(b=='A'||b=='B'||b=='C'){
        flag2=true;
    }
    if(flag1==flag2){
        return true;
    }
    return false;
}
bool check2(char a,char b){
    if(a=='A'&&b=='B'){
        return true;
    }
    if(a=='B'&&b=='A' || a=='B'&&b=='C'){
        return true;
    }
    if(a=='D'&&b=='E'){
        return true;
    }
    return false;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1==c2){
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            if(check(s1[2],s2[2])){
                if(check2(s1[2],s2[2])){
                    cout << "1111";
                    return 0;
                }else{
                    cout << "1110";
                    return 0;
                }
            }else{
                cout << "1100";
                return 0;
            }
        }else{
            cout << "1000";
            return 0;
        }
    }else{
        cout << "0000";
        return 0;
    }
    return 0;
}
