#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a,b,c,d;
int main(){
    freopen("travel","r",stdin);
    freopen("travel","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    a=int(c1[0])*10+int(c1[1]);
    b=int(c2[0])*10+int(c2[1]);
    c=int(s1[0])*10+int(s1[1]);
    d=int(s2[0])*10+int(s2[1]);
    if(a!=b){
        cout<<"0000";
    }
    else{
        cout<<"1";
        if(c!=d){
            cout<<"000";
        }
        else{
            cout<<"1";
            if(s1[2]<='C'&&s2[2]<='C'){
                cout<<"1";
                if(s1[2]=='B'||s2[2]=='B')cout<<"1";
                else cout<<"0";
            }
            else if(s1[2]>'C'&&s2[2]>'C'){
                cout<<"11";
            }
            else{
                cout<<"00";
            }
        }
    }
    return 0;
}
