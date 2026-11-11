#include <bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;
bool check(){
    char a=s1[2],b=s2[2];
    if(abs(a-b)==1)
        return true;
    if((a=='D'&&b=='F')||(a=='F'&&b=='D'))
        return true;
    return false;
}
bool f(){
    char a=s1[2],b=s2[2];
    if((a=='A'||a=='B'||a=='C')&&(b=='A'||b=='B'||b=='C'))
        return true;
    if((a=='D'||a=='F')&&(b=='D'||b=='F'))
        return true;
    return false;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1==c2){
        cout << 1;
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            cout << 1;
            if(f()){
                cout << 1;
                if(check())
                    cout << 1;
                else
                    cout << 0;
            }else{
                cout << "00";
            }
        }
        else{
            cout << "000";
        }
    }else{
        cout << "0000";
    }
    return 0;
}