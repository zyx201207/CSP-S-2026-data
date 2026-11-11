#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string cr;
    string sr;
    string cx;
    string sx;
    cin>>cr>>sr>>cx>>sx;

    if(cr==cx){
        cout<<"1";
        if(sr[0]==sx[0]&&sr[1]==sx[1]){
            cout<<"1";
            if(sr[2]=='F'&&sx[2]=='D'||sx[2]=='F'&&sr[2]=='D'||sr[2]=='A'&&sx[2]=='B'||sr[2]=='B'&&sx[2]=='A'||sr[2]=='B'&&sx[2]=='C'||sr[2]=='C'&&sx[2]=='B'){
                cout<<"11";

            }else if(sr[2]=='A'&&sx[2]=='C'||sr[2]=='C'&&sx[2]=='A'){
            cout<<"10";
            }else{
            cout<<"00";}
        }else{
        cout<<"000";}
    }else{
    cout<<"0000";
    }
    return 0;
}
