#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string R1,R2,X1,X2;
    cin>>R1>>R2>>X1>>X2;
    if(R1==X1){
        if(R2[0]==X2[0]&&R2[1]==X2[1]){
            if(R2[2]<='C'&&X2[2]<='C'||R2[2]>'C'&&X2[2]>'C'){
                if(R2[2]-1==X2[2]||R2[2]+1==X2[2]){
                    cout<<"1111";
                }
                else{
                    cout<<"1110";
                }
            }
            else{
                cout<<"1100";
            }
        }
        else{
            cout<<"1000";
        }
    }
    else{
        cout<<"0000";
    }
    return 0;
}
