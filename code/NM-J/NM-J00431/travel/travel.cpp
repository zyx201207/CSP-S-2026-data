#include<iostream>
#include<string>
using namespace std;
struct ticket{
    string seat;
    int cabin;
};
ticket r;
ticket x;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>r.cabin>>r.seat>>x.cabin>>x.seat;
    if(r.cabin==x.cabin){
        cout<<"1";
        if(r.seat.substr(0,2)==x.seat.substr(0,2)){
            cout<<"1";
            if(((r.seat[2]=='A'||r.seat[2]=='B'||r.seat[2]=='C')&&(x.seat[2]=='A'||x.seat[2]=='B'||x.seat[2]=='C'))||((r.seat[2]=='D'||r.seat[2]=='F')&&(x.seat[2]=='D'||x.seat[2]=='F'))){
                cout<<"1";
                if((r.seat[2]=='A'&&x.seat[2]=='B')||(r.seat[2]=='B'&&(x.seat[2]=='A'||x.seat[2]=='C'))||(r.seat[2]=='C'&&x.seat[2]=='B')||(r.seat[2]=='D'&&x.seat[2]=='F')||(r.seat[2]=='F'&&x.seat[2]=='D')){
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
