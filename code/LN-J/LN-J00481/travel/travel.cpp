#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string acxh,azwh,bcxh,bzwh;
    cin>>acxh>>azwh>>bcxh>>bzwh;
    if(acxh==bcxh){
        cout<<"1";
    }
    else{
        cout<<"0000";
        return 0;
    }
    if((azwh[0]==bzwh[0])&&(azwh[1]==bzwh[1])){
        cout<<"1";
    }
    else{
        cout<<"000";
        return 0;
    }
    if(azwh[2]<='C'&&bzwh[2]<='C'){
        cout<<"1";
    }
    else if(azwh[2]>='D'&&bzwh[2]>='D'){
        cout<<"1";
    }
    else{
        cout<<"00";
        return 0;
    }
    if(abs(azwh[2]-bzwh[2])==1){
        cout<<"1";
    }
    else{
        cout<<"0";
    }
    return 0;
}
