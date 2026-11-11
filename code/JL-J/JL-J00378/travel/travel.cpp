#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel3.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1, sl1, c2, sl2;
    char s1, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2){
        cout << "1";
    }
    else{
        cout << "0";
    }
    sl1 = int(s1);
    sl2 = int(s2);
    if(s1 == s2){
        cout << "1";
    }
    else{
        cout << "0";
    }

    if(s1+1 == s2||s1-1 == s2||s1+2 == s2||s1-2 == s2){
        cout << "1";
    }
    else{
        cout << "0";
    }
    if(s1+1 == s2||s1-1 == s2){
        cout << "1";
    }
    else{
        cout << "0";
    }
    return 0;
}
