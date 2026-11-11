#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,ans;
bool f(string s){if(s[2]=='A' || s[2]=='B' || s[2]=='C'){return 0;}else{return 1;}}
int f2(string s){if(s[2]=='A'){return 1;}else if(s[2]=='B'){return 2;}else if(s[2]=='C'){return 3;}else if(s[2]=='D'){return 5;}else{return 6;}}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){ans+="1";}else{ans+="0000";cout<<ans;return 0;}
    if(s1[0]==s2[0] && s1[1]==s2[1]){ans+="1";}else{ans+="000";cout<<ans;return 0;}
    if(f(s1)==f(s2)){ans+="1";}else{ans+="00";cout<<ans;return 0;}
    if(abs(f2(s1)-f2(s2))==1){ans+='1';}else{ans+='0';cout<<ans;return 0;}
    cout<<ans;
    return 0;
}
