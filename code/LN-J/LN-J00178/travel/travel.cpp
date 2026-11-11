#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a1,a2,b1,b2;
    cin>>a1>>a2>>b1>>b2;
    if(a1!=b1){
        cout<<"0000\n";
        return 0;
    }
    if(a2[0]!=b2[0]||a2[1]!=b2[1]){
        cout<<"1000\n";
        return 0;
    }
    if(a2[2]=='A'||a2[2]=='B'||a2[2]=='C'){
        if(b2[2]=='A'||b2[2]=='B'||b2[2]=='C'){
            if(b2[2]==a2[2]+1||b2[2]==a2[2]-1) cout<<"1111\n";
            else cout<<"1110\n";
        }
        else cout<<"1100\n";
    }
    else{
        if(b2[2]=='D'||b2[2]=='E') cout<<"1111\n";
        else cout<<"1110\n";
    }
    return 0;
}
