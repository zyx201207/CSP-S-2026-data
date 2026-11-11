#include <bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    cin >> c1 >> s1 >> c2 >> s2;
    if(c1==c2){
        cout << 1;
        if(s1[0]==s2[0] && s1[1]==s2[1]){
            cout << 1;
            if(s1[2]*1>=65 && s1[2]*1<=67 && s2[2]*1>=65 && s2[2]*1<=67){
                cout << 1;
                if( abs( int(s1[2]) - int(s2[2]))==1 ) cout << 1;
                else cout << 0;
            }
            else if(s1[2]*1>=68 && s1[2]*1<=70 && s2[2]*1>=68 && s2[2]*1<=70){
                cout << 11;
            }
            else {
                cout << 0;
                cout << 0;
            }
        }
        else{
            cout << 0;
            cout << 0;
            cout << 0;
        }
    }
    else{
        cout << 0;
        cout << 0;
        cout << 0;
        cout << 0;
    }

    return 0;
}
