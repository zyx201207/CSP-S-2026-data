#include<bits/stdc++.h>
using namespace std;
string s[10];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    for(int i=0;i<4;i++){
        cin>>s[i];
    }
    if(s[0]==s[2]){
        cout<<1;
        if(s[1][0]==s[3][0]&&s[1][1]==s[3][1]){
            cout<<1;
            if('A'<=s[1][2]&&s[1][2]<='C'&&'A'<=s[3][2]&&s[3][2]<='C'||s[1][2]=='D'&&s[3][2]=='F'||s[1][2]=='F'&&s[3][2]=='D'){
                cout<<1;
                if(s[1][2]=='A'&&s[3][2]=='B'||s[1][2]=='B'&&s[3][2]=='A'||s[1][2]=='C'&&s[3][2]=='B'||s[1][2]=='B'&&s[3][2]=='C'||s[1][2]=='D'&&s[3][2]=='F'||s[1][2]=='F'&&s[3][2]=='D') cout<<1;
                else cout<<0;
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
