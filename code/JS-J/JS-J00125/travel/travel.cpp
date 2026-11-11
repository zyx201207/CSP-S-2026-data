#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string ca,sa,cx,sx;
    cin>>ca>>sa>>cx>>sx;
    if(ca==cx){
        cout<<1;
    }else{
        cout<<"0000";
        return 0;
    }
    if(sa[0]==sx[0] && sa[1]==sx[1]){
        cout<<1;
    }else{
        cout<<"000";
        return 0;
    }
if((sa[2]=='A'&&sx[2]=='B')||(sa[2]=='A'&&sx[2]=='C')||(sa[2]=='C'&&sx[2]=='A')||(sa[2]=='B'&&sx[2]=='A')||(sa[2]=='B'&&sx[2]=='C')||(sa[2]=='C'&&sx[2]=='B')||(sa[2]=='D'&&sx[2]=='F')||(sa[2]=='F'&&sx[2]=='D')){
        cout<<1;
    }else{
        cout<<"00";
        return 0;
    }
    if((sa[2]=='A'&&sx[2]=='B')||(sa[2]=='B'&&sx[2]=='A')||(sa[2]=='B'&&sx[2]=='C')||(sa[2]=='C'&&sx[2]=='B')||(sa[2]=='D'&&sx[2]=='F')||(sa[2]=='F'&&sx[2]=='D')){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}
