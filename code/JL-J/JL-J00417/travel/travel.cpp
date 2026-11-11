#include <bits/stdc++.h>
using namespace std;
int c1,c2;
vector <char> s1(3);
vector <char> s2(3);
int main(){
    cin >> c1 ;
    for(int i=0;i<3;i++){
        cin >> s1[i];
    }
    cin >> c2;
    for(int i=0;i<3;i++){
        cin >> s2[i];
    }
    if(c1==c2){
        cout << "1";
    }else{
        cout << "0000";
        return 0;
    }
    if(s1[0]==s2[0] && s1[1]==s2[1]){
        cout << "1";
    }else{
        cout << "000";
        return 0;
    }
    if(s1[2]=='A' || s1[2]=='B' || s1[2]=='C'){
        if(s2[2]=='A' || s2[2]=='B' || s2[2]=='C'){
            cout << "1";
        }else{
            cout << "00";
            return 0;
        }
    }else if(s1[2]=='D' || s1[2]=='F'){
        if(s2[2]=='D' || s2[2]=='F'){
            cout << "1";
        }else{
            cout << "00";
        }
    }
    if(s1[2]-s2[2]==1 || s2[2]-s1[2]==1){
        if(s1[2]!='C' && s2[2]!='D'){
            if(s1[2]!='D' && s2[2]!='C'){
                cout << "1";
            }else{
                cout << "0";
            }
        }else{
            cout << "0";
        }
    }else{
        cout << "0";
    }
    return 0;
}
