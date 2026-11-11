#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
string c1,c2,s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2) cout<<1;
    else{
        cout<<"0000";
        return 0;
    }
    string a = s1.substr(0,2);
    string b = s2.substr(0,2);
    if(a==b){
        cout<<1;
    }
    else{
        cout<<"000";
        return 0;
    }
    char c =s1[2],d = s2[2];
    if(c>='A'&&c<='C'&&d>='A'&&d<='C'||c=='D'&&d=='F'||c=='F'&&d=='D'){
        cout<<1;
    }
    else{
        cout<<"00";
        return 0;
    }
    if(c=='A'&&d=='B'||c=='B'&&d=='A'||c=='B'&&d=='C'||c=='C'&&d=='B'||c=='D'&&d=='F'||c=='F'&&d=='D'){
        cout<<1;
    }
    else cout<<0;
}
