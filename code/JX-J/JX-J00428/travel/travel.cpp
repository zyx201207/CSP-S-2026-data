#include <bits/stdc++.h>
using namespace std;
string s;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s;
    int a1=(s[0]-'0')*10+(s[1]-'0');
    cin>>s;
    int a2=(s[0]-'0')*10+(s[1]-'0');
    char a3=s[2];
    cin>>s;
    int b1=(s[0]-'0')*10+(s[1]-'0');
    cin>>s;
    int b2=(s[0]-'0')*10+(s[1]-'0');
    char b3=s[2];
    if(a1==b1){
        cout<<"1";
        if(a2==b2){
            cout<<"1";
            if((a3<='C'&&b3<='C')||(a3>='D'&&b3>='D')){
                cout<<"1";
                if(a3-b3==1||b3-a3==1){
                    cout<<"1";
                }else{
                    cout<<"0";
                }
            }else{
                cout<<"00";
            }
        }else{
            cout<<"000";
        }
    }else{
        cout<<"0000";
    }
    return 0;
}
