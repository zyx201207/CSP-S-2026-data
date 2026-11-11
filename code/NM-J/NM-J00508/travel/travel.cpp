#include <bits/stdc++.h>
using namespace std;
bool near(char a,char b){
    return (b == 'B') ^ (a == 'B');
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;
    cin>>c1>>s1>>c2>>s2;
    cout<<(c1==c2);
    cout<<(c1==c2 && s1.substr(0,2)==s2.substr(0,2));
    if('A' <= s1[2] && s1[2] <= 'C'){
        cout<<(c1==c2 && s1.substr(0,2)==s2.substr(0,2) && 'A' <= s1[2] && s1[2] <= 'C');
        cout<<(c1==c2 && s1.substr(0,2)==s2.substr(0,2) && 'A' <= s1[2] && s1[2] <= 'C' && near(s1[2],s2[2]));
    }
    else{
        cout<<(c1==c2 && s1.substr(0,2)==s2.substr(0,2) && ('D' == s1[2] || s1[2] == 'F'));
        cout<<(c1==c2 && s1.substr(0,2)==s2.substr(0,2) && ('D' == s1[2] || s1[2] == 'F'));
    }
}
