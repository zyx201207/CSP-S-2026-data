#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    for(int i=0;i<13;i++)cin>>s[i];
    if(s[0]==s[5]&&s[1]==s[6]){
        cout<<'1';
        if(s[2]==s[7]&&s[3]==s[8]){
            cout<<'1';
            if((s[4]<='C'&&s[9]<='C')||(s[4]>='D'&&s[9]>='D')){
                cout<<'1';
                if(abs(s[4]-s[9])==1)cout<<'1';
                else cout<<'0';
            }else cout<<"00";
        }else cout<<"000";
    }else cout<<"0000";
    return 0;
}
