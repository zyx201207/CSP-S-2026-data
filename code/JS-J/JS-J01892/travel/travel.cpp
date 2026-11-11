#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.ans","w",stdout);
    string c,c1,c2,c3;
    cin>>c>>c1>>c2>>c3;
    if(c!=c2){
        cout<<"0000";
        return 0;
    }else{
        if(c1==c3){
            cout<<"1110";
            return 0;
        }
        cout<<"1";
    }
    if(c1[0]==c3[0]&&c1[1]==c3[1])
        cout<<"1";
    else{
        cout<<"000";
        return 0;
    }
    if((c1[2]=='A'&&c3[2]=='B')||(c1[2]=='B'&&c3[2]=='C')||(c3[2]=='A'&&c1[2]=='B')||(c1[2]=='C'&&c3[2]=='B')){
        cout<<"11";
        return 0;
    }else if((c1[2]=='D'&&c3[2]=='F')||(c3[2]=='D'&&c1[2]=='F')){
        cout<<"11";
        return 0;
    }else{
        cout<<"10";
    }
    return 0;
}
