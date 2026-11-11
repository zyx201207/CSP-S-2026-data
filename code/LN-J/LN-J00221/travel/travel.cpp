#include<bits/stdc++.h>
using namespace std;
string r1,r2,x1,x2;
bool is_side(char x,char y){
  if((x=='A'||x=='B'||x=='C')&&(y=='A'||y=='B'||y=='C')){
        return true;
    }
    else if((x=='D'||x=='F')&&(y=='D'||y=='F')){
        return true;
    }
    else return false;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>r1>>r2>>x1>>x2;
    if(r1!=x1) {
        cout<<"0000";
        return 0;
    }
    else {
        cout<<"1";
        if(r2[1]!=x2[1]){
            cout<<"000";
            return 0;
        }
        else {
            cout<<"1";
            if(!is_side(r2[2],x2[2])){
                cout<<"00";
                return 0;
            }
            else{
                cout<<"1";
                if(abs((r2[2]-'A')-(x2[2]-'A'))!=1){
                    cout<<"0";
                    return 0;
                }
                else {
                    cout<<"1";
                    return 0;
                }
            }
        }

    }
    return 0;
}


