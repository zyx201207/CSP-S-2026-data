#include<bits/stdc++.h>
using namespace std;
string c,s,sc,cs;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c>>s>>sc>>cs;
    if(c!=sc){
        cout<<"0000";
    }
    else{
        cout<<"1";
        if(s[1]!=cs[1]){
            cout<<"000";
        }
        else{
            cout<<"1";
            if(s[2]=='D'&&cs[2]=='F'||s[2]=='A'&&cs[2]=='B'||s[2]=='B'&&cs[2]=='A'||s[2]=='C'&&cs[2]=='A'||s[2]=='A'&&cs[2]=='C'||s[2]=='B'&&cs[2]=='C'||s[2]=='C'&&cs[2]=='B'){
                cout<<"1";
                if(s[2]==cs[2]+1||s[2]==cs[2]-1){
                    cout<<"1";
                }
                else{
                    cout<<"0";
                }

            }
            else{
                cout<<"00";
            }
        }
    }
    return 0;
}
