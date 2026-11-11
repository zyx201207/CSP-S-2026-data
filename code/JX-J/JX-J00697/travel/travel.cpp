#include<bits/stdc++.h>
using namespace std;
string s;
int c1,s1,c2,s2,sum;
char k1,k2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s;
    c1=(s[0]-'0')*10+s[1]-'0';
    cin>>s;
    s1=(s[0]-'0')*10+s[1]-'0';
    k1=s[2];
    cin>>s;
    c2=(s[0]-'0')*10+s[1]-'0';
    cin>>s;
    s2=(s[0]-'0')*10+s[1]-'0';
    k2=s[2];
    if(c1==c2){
        cout<<1;
        if(s1==s2){
            cout<<1;
            if((k1<='C'&&k2<='C')||(k1>'C'&&k2>'C')){
                cout<<1;
                if(abs(k1-k2)==1)
                    cout<<1;
                else
                    cout<<0;
            }
            else
                cout<<"00";
        }
        else
            cout<<"000";
    }
    else
        cout<<"0000";
    return 0;
}
