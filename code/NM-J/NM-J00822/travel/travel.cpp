#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string rc,rs,xc,xs,rp="00",xp="00";
    cin>>rc>>rs>>xc>>xs;
    if(rc!=xc){
        cout<<"0000";
    }
    else{
        rp[0]=rs[0];
        rp[1]=rs[1];
        xp[0]=xs[0];
        xp[1]=xs[1];
        if(rp==xp){
            cout<<"11";
            if((rs[2]=='A' or rs[2]=='B' or rs[2]=='C') and (xs[2]=='A' or xs[2]=='B' or xs[2]=='C')){
                cout<<"1";
                if(rs[2]-xs[2]!=2 and xs[2]-rs[2]!=2){
                    cout<<"1";
                }
                else{
                    cout<<"0";
                }
            }
            else if((rs[2]=='D' or rs[2]=='F') and (xs[2]=='D' or xs[2]=='F')){
                cout<<"11";
            }
            else{
                cout<<"00";
            }
        }
        else{
            cout<<"1000";
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
