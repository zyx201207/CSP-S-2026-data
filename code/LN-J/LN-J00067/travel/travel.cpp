#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in",'r',stdin);
    freopen("travel.out",'w',stdout);
    int ac,bc;
    char a10,a1,b10,b1,a,b;
    cin>>ac>>a10>>a1>>a>>bc>>b10>>b1>>b;
    if(ac==bc){
        if(a10==b10&&a1==b1){
            if((a=='D'&&b=='F')||(a=='F'&&b=='D')||(a=='A'&&b=='B')||(a=='B'&&b=='A')||(a=='A'&&b=='C')||(a=='C'&&b=='A')||(a=='B'&&b=='C')||(a=='C'&&b=='B')){
                if((a=='D'&&b=='F')||(a=='F'&&b=='D')||(a=='A'&&b=='B')||(a=='B'&&b=='A')||(a=='B'&&b=='C')||(a=='C'&&b=='B')){
                    cout<<"1111";
                }
                else{
                    cout<<"1110";
                }
            }
            else{
                cout<<"1100";
            }
        }
        else{
            cout<<"1000";
        }
    }
    else{
        cout<<"0000";
    }
    return 0;
}

//CCF wan4 sui4!!!
//CCF yong3 chui2 bu4 xiu3!
//CCF RP++!
//CSP RP++!
//luogu RP++!
