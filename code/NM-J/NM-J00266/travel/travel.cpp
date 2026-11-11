#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    string rcar,rseat,xcar,xseat;
    cin>>rcar>>rseat>>xcar>>xseat;
    if(rcar==xcar){
        cout<<1;
        if(rseat[1]==xseat[1]&&rseat[0]==xseat[0]){
            cout<<1;
            if(((rseat[2]=='A'||rseat[2]=='B'||rseat[2]=='C')&&(xseat[2]=='A'||xseat[2]=='B'||xseat[2]=='C'))||
            ((rseat[2]=='D'||rseat[2]=='F')&&(xseat[2]=='D'||xseat[2]=='F'))){
                cout<<1;
                if((rseat[2]=='A'&&xseat[2]=='B')||(rseat[2]=='B'&&xseat[2]=='A')||(rseat[2]=='B'&&xseat[2]=='C')
                    ||(rseat[2]=='C'&&xseat[2]=='B')||(rseat[2]=='D'&&xseat[2]=='F')||(rseat[2]=='F'&&xseat[2]=='D')){
                        cout<<1;
                    }else cout<<0;
            }else cout<<"00";
        }else cout<<"000";
    }else cout<<"0000";


    return 0;
}
