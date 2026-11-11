#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string ans = "1111";
bool tongyice(char c,char d){
    if(c == 'A'){
        return d == 'B' || d == 'C';
    }
    if(c == 'B'){
        return d == 'A' || d == 'C';
    }
    if(c == 'C'){
        return d == 'A' || d == 'B';
    }
    if(c == 'D')return d == 'F';
    if(c == 'F')return d == 'D';
}
bool xianglin(char c,char d){
    if(c == 'A')return d == 'B';
    if(c == 'B')return d == 'A' || d == 'C';
    if(c == 'C')return d == 'B';
    if(c == 'D')return d == 'F';
    if(c == 'F')return d == 'D';
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 != c2){
        ans = "0000";
        cout << ans;
        return 0;
    }
    string a,b;
    a.push_back(s1[0]);
    a.push_back(s1[1]);
    b.push_back(s2[0]);
    b.push_back(s2[1]);
    char c = s1[2];
    char d = s2[2];
    if(a != b){
        cout << "1000";
        return 0;
    }
    if(!tongyice(c,d)){
        cout << "1100";
        return 0;
    }
    if(!xianglin(c,d)){
        cout << "1110";
        return 0;
    }
    cout << "1111";
    return 0;
}