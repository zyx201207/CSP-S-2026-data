#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string c1,c2,c3,c4;
bool pand(char a,char b){
    if((a=='A'&&b=='B')||(a=='B'&&b=='A')||(a=='B'&&b=='C')||(a=='C'&&b=='B')||(a=='D'&&b=='F')||(a=='F'&&b=='D')){
        return true;
    }
    return false;
}
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c1>>c2>>c3>>c4;
    if(c1==c3){
        cout<<1;
    }else {
        cout<<"0000";
        return 0;
    }
    if(c2[0]+c2[1]==c4[0]+c4[1]){
        cout<<1;
    }else {
        cout<<"000";
        return 0;
    }
    if((c2[2]<='C'&&c4[2]<='C')||(c2[2]>='D'&&c4[2]>='D')){
        cout<<1;
    }else {
        cout<<"00";
        return 0;
    }
    if(pand(c2[2],c4[2])) {
            cout<<1;
    }else cout<<0;
    return 0;
}
