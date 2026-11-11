#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,s1,s2;
    cin >> a >> s1 >> b >> s2;
    if(a[0] == b[0] && a[1] == b[1]) cout << "1";
    else{
        cout << "0000";
        return 0;
    }
    if(s1[0] = s2[0] && s1[1] == s2[1]) cout << "1";
    else{
        cout << "000";
        return 0;
    }
    if(s1[2] > 'C' && s2[2] > 'C'){
        cout << "1";
    }
    else if(s1[2] <= 'C' && s2[2] <= 'C'){
        cout << "1";
    }
    else{
        cout << "00";
        return 0;
    }
    if(s1[2] + 1 == s2[2] || s1[2] - 1 == s2[2]){
        if(s1[2] == 'C' && s2[2] == 'D'){
            cout << "0";
        }
        else if(s1[2] == 'D' && s2[2] == 'C'){
            cout << "0";
        }
        else{
            cout << "1";
        }
    }
    else{
        cout << "0";
    }
    return 0;
}
