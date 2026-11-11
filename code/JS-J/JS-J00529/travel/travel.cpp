#include<bits/stdc++.h>
using namespace std;
string R,R1,X,X1;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>R>>R1>>X>>X1;
    if(R==X){
        if(R1[0]==X1[0]&&R1[1]==X1[1]){
            if(R1[2]=='C'||R1[2]=='B'){
                if(X1[2]=='B'||X1[2]=='C'){
                    cout<<1111;
                    return 0;
                }
            }
            if(R1[2]=='A'||R1[2]=='C'){
                if(X1[2]=='C'||X1[2]=='A'){
                    cout<<1110;
                    return 0;
                }
            }
            if(R1[2]=='A'||R1[2]=='B'){
                if(X1[2]=='B'||X1[2]=='A'){
                    cout<<1111;
                    return 0;
                }
            }
            if(R1[2]=='F'||R1[2]=='D'){
                if(X1[2]=='D'||X1[2]=='F'){
                    cout<<1111;
                    return 0;
                }
            }
        }
        else{
            cout<<"1000";
            return 0;
        }
    }
    else{
        cout<<"0000";
        return 0;
    }
    cout<<"1100";


return 0;
}
