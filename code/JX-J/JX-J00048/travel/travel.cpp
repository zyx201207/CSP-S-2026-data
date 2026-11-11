#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int cxh_R,cxh_X;
    string zwh_R,zwh_X;
    cin>>cxh_R>>zwh_R>>cxh_X>>zwh_X;
    if(cxh_R==cxh_X){
        cout<<"1";
        char r = zwh_R[2],x = zwh_X[2];
        if(zwh_R[0]==zwh_X[0]&&zwh_R[1]==zwh_X[1]){
            cout<<"1";
            if((r>='D'&&x>='D')||(r<='C'&&x<='C')){
                cout<<"1";
                if((r=='D'&&x=='F')||(r=='F'&&x=='D')){
                    cout<<"1";
                }
                else if((r=='C'&&x=='B')||(r=='B'&&x=='C')||(r=='B'&&x=='A')||(r=='A'&&x=='B')){
                    cout<<"1";
                }
                else{
                    cout<<"0";
                }
            }
            else{
                cout<<"00";
            }
        }
        else{
            cout<<"000";
        }
    }
    else{
        cout<<"0000";
    }
    return 0;
}
