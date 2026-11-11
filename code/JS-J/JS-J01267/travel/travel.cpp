#include <bits/stdc++.h>
using namespace std;

string c1,c2,s1,s2;
string s;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2){
        s = s+"1";
    }
    else{
        return cout << "0000",0;
    }

    if(s1[0] == s2[0] && s1[1] == s2[1]){
        s = s+"1";
    }
    else{
        s = s+"000";
        return cout << s,0;
    }

    if(s1[2] >= 'A' && s1[2] <= 'C' && s2[2] >= 'A' && s2[2] <= 'C'){
        s = s+"1";
        if(s1[2] == 'A' && s2[2] == 'C' || s1[2] == 'C' && s2[2] == 'A'){
            s = s+"0";
        }
        else{
            s = s+"1";
        }
        return cout << s,0;
    }
    else if(s1[2] >= 'D' && s1[2] <= 'F' && s2[2] >= 'D' && s2[2] <= 'F'){
        s = s+"11";
        return cout << s,0;
    }
    else{
        s = s+"00";
        return cout << s,0;
    }



}
