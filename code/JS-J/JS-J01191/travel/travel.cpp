#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string rc,rl,xc,xl;
    cin>>rc>>rl>>xc>>xl;
    if(rc==xc){
        cout<<"1";
        if(rl[0]==xl[0]&&rl[1]==xl[1]){
            cout<<"1";
            if(((rl[2]=='A'||rl[2]=='B'||rl[2]=='C')&&(xl[2]=='A'||xl[2]=='B'||xl[2]=='C'))||((rl[2]=='D'||rl[2]=='F')&&(xl[2]=='D'||xl[2]=='F'))){
                cout<<"1";
                if((rl[2]=='A'&&xl[2]=='B')||(rl[2]=='B'&&xl[2]=='A')||(rl[2]=='B'&&xl[2]=='C')||(rl[2]=='C'&&xl[2]=='B')||(rl[2]=='D'&&xl[2]=='F')||(rl[2]=='F'&&xl[2]=='D')){
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
