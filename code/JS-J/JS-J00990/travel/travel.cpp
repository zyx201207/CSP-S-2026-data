#include<bits/stdc++.h>
using namespace std;
string rbox,rseat,xbox,xseat,ans;
long long rpos,xpos;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>rbox>>rseat>>xbox>>xseat;
    if(rbox != xbox){
        cout<<"0000";
        return 0;
    }
    else{
        if(rseat[0] == xseat[0] && rseat[1] == xseat[1]){
            rpos = rseat[2]-'A';
            xpos = xseat[2]-'A';
            if((xpos<=2 && rpos <= 2) || (xpos >= 3 && rpos >= 3)){
                if(abs(xpos-rpos) == 1){
                    cout<<"1111";
                    return 0;
                }
                else{
                    cout<<"1110";
                    return 0;
                }
            }
            else{
                cout<<"1100";
            }
        }
        else{
            cout<<"1000";
            return 0;
        }
    }
    return 0;
}
