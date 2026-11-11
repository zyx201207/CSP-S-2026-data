#include<bits/stdc++.h>
using namespace std;
int main(){

    freopen("travel.in","r",stdin);
    freopen("travel.in","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==c){//1
        cout<<"1";
        if(b[0]==d[0]&&d[1]==d[1]){//2
            cout<<"1";
            if((b[2]=='A'&&d[2]=='B')||(b[2]=='B'&&d[2]=='A')||(b[2]=='B'&&d[2]=='C')||(b[2]=='C'&&d[2]=='B')||(b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D')){
                cout<<"11";
            }else if((b[2]=='A'&&d[2]=='C')||(b[2]=='C'&&d[2]=='A')){
                cout<<"10";
            }else{
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
// "AC" AD AF  BD BF CD CF
