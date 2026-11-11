#include<bits/stdc++.h>
using namespace std;
long long cc(char x){
    if(x == 'A' || x == 'B' || x == 'C') return 0;
    return 1;
}
long long wh(char x){
    if(x == 'A') return 1;
    if(x == 'B') return 2;
    if(x == 'C') return 3;
    if(x == 'D') return 4;
    return 5;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long ca,cb;
    string za,zb;
    cin>>ca>>za>>cb>>zb;
    if(ca == cb){
        cout<<"1";
        long long pa = stoll(za.substr(0,2));
        long long pb = stoll(zb.substr(0,2));
        if(pa == pb){
            cout<<"1";
            if(cc(za[2]) == cc(zb[2])){
                cout<<"1";
                if(abs(wh(za[2])-wh(zb[2])) == 1){
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
