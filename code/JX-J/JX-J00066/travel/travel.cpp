#include<string>
#include<iostream>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    string r,R,c,C;
    cin>>r>>R>>c>>C;
    if(r==c){cout<<1;}
    else{cout<<0;cout<<0;cout<<0;cout<<0;return 0;}
    if(R[0]==C[0] && R[1]==C[1]){
        cout<<1;
        if(R[2]>='A' && C[2]>='A' &&R[2]<='C' && C[2]<='C'){
            cout<<1;
            if(R[2]==C[2]+1 || C[2]==R[2]+1){
                cout<<1;
            }
            else
                cout<<0;
        }
        else if((R[2]=='D' || R[2]=='F') && (C[2]=='D' || C[2]=='F')){
            cout<<11;
        }
        else{
            cout<<0;cout<<0;
        }
    }
    else{cout<<0;cout<<0;cout<<0;}
    return 0;
}