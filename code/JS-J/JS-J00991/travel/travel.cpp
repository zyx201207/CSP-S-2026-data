#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string cr,cs,xr,xs;
    cin>>cr>>cs>>xr>>xs;
    if(cr==xr){
        cout<<'1';
    }
    else{
        cout<<"0000";
        return 0;
    }
    if(cs[0]==xs[0]&&cs[1]==xs[1]){
        cout<<'1';
    }
    else{
        cout<<"000";
        return 0;
    }
    if(cs[2]=='A'||cs[2]=='B'||cs[2]=='C'){
        if(xs[2]=='A'||xs[2]=='B'||xs[2]=='C'){
            cout<<'1';
        }
        else{
            cout<<"00";
            return 0;
        }
    }
    else{
        if(xs[2]=='D'||xs[2]=='E'){
            cout<<'1';
        }
        else{
            cout<<"00";
            return 0;
        }
    }
    if(cs[2]-xs[2]==1||xs[2]-cs[2]==1){
        cout<<'1';
        return 0;
    }
    else{
        cout<<'0';
        return 0;
    }
}
