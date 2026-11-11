#include <iostream>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    bool a=false,b=false,c=false,d=false;
    if(c1==c2) a=true;
    if(a&&s1.substr(0,2)==s2.substr(0,2)) b=true;
    int ss1=s1[2]-'0',ss2=s2[2]-'0';
    if(b&&abs(ss1-ss2)<=2&&(!(s1[2]=='C'&&s2[2]=='D')&&!(s1[2]=='D'&&s2[2]=='C'))) c=true;
    if(c&&abs(ss1-ss2)==1) d=true;
    cout<<a<<b<<c<<d;
    return 0;
}
