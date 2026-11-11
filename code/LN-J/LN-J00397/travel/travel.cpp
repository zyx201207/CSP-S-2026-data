#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool a,b,c,d;
bool zuo,you;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c1>>s1>>c2>>s2;
    if(c1[0]==c2[0]&&c1[1]==c2[1]) a=true;
    if(s1[0]==s2[0]&&s1[1]==s2[1]&&a==true) b=true;
    if(a==true&&b==true){
        if(s1[2]<='C'&&s2[2]<='C'){
            zuo=true;
            c=true;
        }
        if(s1[2]>'C'&&s2[2]>'C'){
            you=true;
            c=true;
        }
    }
    if(a==true&&b==true&&c==true){
        if(you==true) d=true;
        if(zuo==true){
            int cha=0;
            cha=abs(s1[2]-s2[2]);
            if(cha==1) d=true;
        }
    }
    cout<<a<<b<<c<<d;
    return 0;
}