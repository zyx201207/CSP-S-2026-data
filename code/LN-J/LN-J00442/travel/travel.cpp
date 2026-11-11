#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int tonum(string s){
if(s[0]=='0'){
    int a=s[1]-'0';
    return a;
}
else{
    int b=s[0]-'0';
    int c=s[1]-'0';
    int d=b*10+c;
    return d;
}
}
bool ce(string e,string f){
if(e[2]=='A'&&f[2]=='B'||e[2]=='B'&&f[2]=='A'||e[2]=='B'&&f[2]=='C'||e[2]=='C'&&f[2]=='B'||e[2]=='A'&&f[2]=='C'||e[2]=='C'&&f[2]=='A'||e[2]=='D'&&f[2]=='F'||e[2]=='F'&&f[2]=='D'){
return 1;
}
else return 0;
}
bool lin(string g,string h){
if(g[2]=='A'&&h[2]=='B'||g[2]=='B'&&h[2]=='A'||g[2]=='B'&&h[2]=='C'||g[2]=='C'&&h[2]=='B'||g[2]=='D'&&h[2]=='F'||g[2]=='F'&&h[2]=='D'){
    return 1;
}
else return 0;
}
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
cin>>c1>>s1>>c2>>s2;
if(c1!=c2){
    cout<<"0000";
    return 0;
}
else{
    cout<<"1";
    if(tonum(s1)!=tonum(s2)){
        cout<<"000";
        return 0;
    }
    else{
        cout<<"1";
        if(ce(s1,s2)==0){
            cout<<"00";
            return 0;
        }
        else{
            cout<<"1";
            if(lin(s1,s2)==0){
                cout<<"0";
                return 0;
            }
            else cout<<"1";
        }
    }
}

return 0;
}
