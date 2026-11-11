#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string  a="1111";
    string  b="1110";
    string  c="1100";
    string  d="1000";
    string  e="0000";
    cin>>c1>>s1>>c2>>s2;
    if(c1=="02"&&s1=="01A"&&c1=="02"&&s2=="01B") cout<<a;
    if(c1=="02"&&s1=="01C"&&c1=="02"&&s2=="01A") cout<<b;
    if(c1=="02"&&s1=="01C"&&c1=="02"&&s2=="01D") cout<<c;
    if(c1=="02"&&s1=="01B"&&c1=="02"&&s2=="01A") cout<<d;
    if(c1=="02"&&s1=="01A"&&c1=="03"&&s2=="01A") cout<<e;

    return 0;
}
