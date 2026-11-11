#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string A,B,C,D;
    cin>>A>>B>>C>>D;
    if(A!=C){
        cout<<"0000";
    }else{
        if(B.substr(0,2)!=D.substr(0,2)){
            cout<<"1000";
        }else{
            if((B[2]<='C')!=(D[2]<='C')){
                cout<<"1100";
            }else{
                if((B[2]=='A'&&D[2]=='C')||(B[2]=='C'&&D[2]=='A')){
                    cout<<"1110";
                }else{
                    cout<<"1111";
                }
            }
        }
    }
    return 0;
}