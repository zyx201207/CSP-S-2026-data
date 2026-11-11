#include<bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> c2 >> c3 >> c4;
    if(c1==c3){
        cout << '1';
        if(c2[0]==c4[0]&&c2[1]==c4[1]){
            cout <<'1';
        }
        else{
            cout << "000";
            return 0;
        }
        if(c2[2]>='A'&&c2[2]<='C'&&c4[2]>='A'&&c4[2]<='C'){
            cout << '1';
        }
        else if(c2[2]>='D'&&c2[2]<='E'&&c4[2]>='D'&&c4[2]<='E'){
            cout << '1';
        }
        else{
            cout << "00";
            return 0;
        }
        char c=c2[2];
        char s1=c+1,s2=c-1;
        if(s1==c4[2]||s2==c4[2])cout << '1';
        else cout << '0';

    }
    else{
        cout << "0000";
    }
    return 0;
}

