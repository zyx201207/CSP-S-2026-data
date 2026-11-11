#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string cr,sr,cx,sx;
    cin>>cr>>sr>>cx>>sx;
    if(cr==cx){
        cout<<1;
        if((sr[0]==sx[0])&&(sr[1]==sx[1])){
            cout<<1;
            char r=sr[2];
            char x=sx[2];
            if( (((r=='A')||(r=='B')||(r=='C'))&&((x=='A')||(x=='B')||(x=='C'))) || ((r=='D')||(r=='F')&&((r=='D')||(r=='F'))) ){
                cout<<1;
                if( (((r=='A')||(r=='B')||(r=='C'))&&((x=='A')||(x=='B')||(x=='C')))&&(abs(r-x)==1) || ((r=='D')||(r=='F')&&((r=='D')||(r=='F'))) ){
                    cout<<1;
                    return 0;
                }
                else{
                    cout<<0;
                    return 0;
                }
            }
            else{
                cout<<"00";
                return 0;
            }
        }
        else{
            cout<<"000";
            return 0;
        }
    }
    else{
        cout<<"0000";
        return 0;
    }
}
