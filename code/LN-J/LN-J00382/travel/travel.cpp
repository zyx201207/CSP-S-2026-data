#include <bits/stdc++.h>
using namespace std;
string ac,al,bc,bl;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>ac>>al>>bc>>bl;
    if(ac==bc){
        cout<<1;
    }
    else{
        cout<<"0000";
        return 0;
    }
    for(int i=0;i<2;i++){
        if(al[i]!=bl[i]){
            cout<<"000";
            return 0;
        }
    }
    cout<<1;
    if((al[2]=='A'||al[2]=='B'||al[2]=='C')&&(bl[2]=='A'||bl[2]=='B'||bl[2]=='C')&&al[2]!=bl[2]){
        cout<<1;
    }
    else if((al[2]=='D'||al[2]=='E')&&(bl[2]=='D'||bl[2]=='E')&&al[2]!=bl[2]){
        cout<<11;
        return 0;
    }
    else{
        cout<<"00";
        return 0;
    }
    if(abs(al[2]-bl[2])==1){
        cout<<1;
    }
    else{
        cout<<"0";
    }
    return 0;
}
