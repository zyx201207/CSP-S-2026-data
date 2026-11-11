
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    int a1=0,c1=0;
    a1=(a[0]-'0')*10+a[1]-'0';
    c1=(c[0]-'0')*10+c[1]-'0';
    if(a1!=c1){
        cout<<"0000";return 0;
    }
    int b1=0,d1=0;
    b1=(b[0]-'0')*10+b[1]-'0';
    d1=(d[0]-'0')*10+d[1]-'0';
    if(b1!=d1){
        cout<<"1000";return 0;
    }
    if((b[2]=='F'||b[2]=='D')&&(d[2]=='C'||d[2]=='B'||d[2]=='A')||(d[2]=='F'||d[2]=='D')&&(b[2]=='C'||b[2]=='B'||b[2]=='A')){
        cout<<"1100";return 0;
    }
    if((b[2]=='C'&&d[2]=='A')||(b[2]=='A'&&d[2]=='C')){
        cout<<"1110";return 0;
    }
    cout<<"1111";
    return 0;
}
