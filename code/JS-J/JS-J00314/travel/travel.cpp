#include<bits/stdc++.h>
using namespace std;
bool check(char x,char y){
    if(x=='A'){
        if(y=='B') return 1;
        else return 0;
    }
    if(x=='B') return 1;
    if(x=='C'){
        if(y=='B') return 1;
        else return 0;
    }
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string wx,wr,pzx,pzr;
    cin>>wr>>pzr>>wx>>pzx;
    if(wr==wx) cout<<1;
    else{
        cout<<"0000";
        return 0;
    }
    if(pzr[0]==pzx[0] && pzr[1]==pzx[1]){
        cout<<1;
    }else{
        cout<<"000";
        return 0;
    }
    bool ok=false;
    char ss=pzr[2];
    if(pzr[2]=='A' || pzr[2]=='B' || pzr[2]=='C')ok=true;
    if(ok){
        if(pzx[2]=='A' || pzx[2]=='B' || pzx[2]=='C'){
            cout<<1;
            if(check(ss,pzx[2])) cout<<1;
            else cout<<0;
        }
        else{
            cout<<"00";
            return 0;
        }
    }
    else{
        if(pzx[2]=='D' || pzx[2]=='F'){
            cout<<11;
            return 0;
        }
        else {
            cout<<"00";
            return 0;
        }
    }


    return 0;
}
