#include<bits/stdc++.h>
using namespace std;
string x,r,xx,rr;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>x>>xx>>r>>rr;
    if(x!=r){
        cout<<"0000";
        return 0;
    }else{
        cout<<"1";
        if(xx[1]!=rr[1]||xx[0]!=rr[0]){
            cout<<"000";
            return 0;
        }
        else{
            cout<<"1";
            if(xx[2]=='F'&&rr[2]!='D'||xx[2]=='D'&&rr[2]!='F'||rr[2]=='D'&&xx[2]!='F'||rr[2]=='F'&&xx[2]!='D'){
                cout<<"00";
                return 0;
            }else if(xx[2]=='D'&&rr[2]=='F'||xx[2]=='F'&&rr[2]=='D'){
                cout<<"11";
                return 0;
            }
            else{
                cout<<"1";
                if(xx[2]=='A'&&rr[2]=='C'||xx[2]=='C'&&rr[2]=='A'){
                    cout<<"0";
                    return 0;
                }
                else cout<<"1";
            }
        }
    }
    return 0;
}
