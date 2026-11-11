//Trick||Treat!
#include<bits/stdc++.h>
#define LL long long
using namespace std;
struct ticket{
    string car,seat;
}a,b;
bool sidea,sideb;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a.car>>a.seat>>b.car>>b.seat;
    int x=a.seat[2],y=b.seat[2];
    if(a.seat[2]=='F' || a.seat[2]=='D')
        sidea=1;
    if(b.seat[2]=='D' || b.seat[2]=='F')
        sideb=1;
    if(a.car==b.car){
        cout<<1;
        if(a.seat[0]==b.seat[0] && a.seat[1]==b.seat[1]){
            cout<<1;
            if(sidea==sideb){
                cout<<1;
                if(fabs(x-y)==1)
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

