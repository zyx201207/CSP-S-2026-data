#include<bits/stdc++.h>
using namespace std;

string c1,c2,c3,c4;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>c2>>c3>>c4;
    if(c1!=c3)cout<<"0000";
    else if((c2[0]!=c4[0])||(c2[1]!=c4[1]))cout<<"1000";
    else if(c2[2]=='D'||c2[2]=='F'){
        if(c4[2]=='D'||c4[2]=='E'){
            cout<<"1111";
        }else{
            cout<<"1100";
        }
    }else{
        if(c4[2]=='D'||c4[2]=='E'){
            cout<<"1100";
        }else{
            if(c4[2]=='A'&&c2[2]=='C'){
                cout<<"1110";
            }else if(c2[2]=='A'&&c4[2]=='C'){
                cout<<"1110";
            }else{
                cout<<"1111";
            }
        }
    }
    return 0;
}
