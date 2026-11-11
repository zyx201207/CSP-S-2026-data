#include<bits/stdc++.h>
using namespace std;
string  az,bz,chea,cheb;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>chea>>az>>cheb>>bz;
    if(chea[0]==cheb[0]&&chea[1]==cheb[1]){
        cout<<"1";
    }
    else {
        cout<<"0"<<"0"<<"0"<<"0";
        return 0;
    }
    if(az[0]==bz[0]&&az[1]==bz[1]){
        cout<<"1";
    }
    else{
        cout<<"0"<<"0"<<"0";
        return 0;
    }
    if(((az[2]=='A'||az[2]=='B'||az[2]=='C')&&(bz[2]=='A'||bz[2]=='B'||bz[2]=='C'))||((az[2]=='D'||az[2]=='E')&&(bz[2]=='D'||bz[2]=='E'))){
        cout<<"1";
    }
    else{
        cout<<"0"<<"0";
        return 0;
    }
    if(az[2]-bz[2]==1||az[2]-bz[2]==-1){
        cout<<"1";
        return 0;
    }
    cout<<"0";
    return 0;
}
