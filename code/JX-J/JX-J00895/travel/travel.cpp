#include<bits/stdc++.h>
using namespace std;
string c,s,C,S;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c>>s>>C>>S;
    if(c==C){
        cout<<'1';
        if(s[0]==S[0] && s[1]==S[1]){
            cout<<'1';
            if(s[2]!=S[2] && (((s[2]=='A' || s[2]=='B' || s[2]=='C') && (S[2]=='A' || S[2]=='B' || S[2]=='C')) || ((s[2]=='D' || s[2]=='F') && (S[2]=='D' || S[2]=='F')))){
                cout<<'1';
                if((abs(int(s[2])-int(S[2]))==1) || ((s[2]=='D' && S[2]=='F') || (s[2]=='F' && S[2]=='D'))){
                    cout<<'1';
                }else{
                    cout<<'0';
                }
            }else{
                cout<<"00";
            }
        }else{
            cout<<"000";
        }
    }else{
        cout<<"0000";
    }
    return 0;
}