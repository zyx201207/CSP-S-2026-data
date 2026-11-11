#include<bits/stdc++.h>
using namespace std;
int main(){

    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    int f1=0,f2=0,f3=0,f4=0;
    string S1;
    string S2;
    string C1;
    string C2;
    cin>>C1>>S1>>C2>>S2;
    if(C1==C2){
        f1=1;
        if(S1[0]==S2[0] && S1[1]==S2[1]){
        f2=1;
        if(((S1[2]>='A' && S1[2]<='C') && (S2[2]>='A' && S2[2]<='C')) || ((S1[2]=='D' && S2[2]=='F') || (S1[2]=='F' && S2[2]=='D'))){
            f3=1;
            if(!((S1[2]=='A' && S2[2]=='C') || (S1[2]='C' && S2[2]=='A'))){
                f4=1;
            }
        }
    }
    }
    cout<<f1<<f2<<f3<<f4;
    return 0;
}

