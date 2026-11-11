#include <bits/stdc++.h>
using namespace std;
string a,a1,b,b1;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    //1
    if(a==b) cout << "1";
    else{
        cout << "0000";
        return 0;
    }
    //2
    if(a1[0]==b1[0] && a1[1]==b1[1])cout << "1";
    else {
        cout << "0";
    }
    //3
    if((a1[0]==b1[0] && a1[1]==b1[1]) && (a1[2]=='C'||b1[2]=='D' && a1[2]=='D'||b1[2]=='C')) cout << "0";
    else{
        cout << "1";
    }
    //4
    if(max((int)a1[2],(int)b1[2]) - min((int)a1[2],(int)b1[2])==1) cout << "1";
    else{
        cout << "0";
    }
    return 0;
}
