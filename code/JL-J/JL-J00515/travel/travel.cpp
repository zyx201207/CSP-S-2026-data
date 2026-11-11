#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4,s5,s6;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>s2>>s3>>s4;
    s5=s2.substr(0,2);
    s6=s2.substr(0,2);
    if(s1!=s3){
        cout<<"0000";
    }else if(s5!=s6){
        cout<<"1000";
    }else{
        if(s2[2]=='A' || s2[2]=='B' || s2[2]=='C'){
            if(s4[2]=='A' || s4[2]=='B' || s4[2]=='C'){
                if(s2[2]+1==s4[2] || s4[2]+1==s2[2]){
                    cout<<"1111";
                }else{
                    cout<<"1110";
                }
            }else{
                cout<<"1100";
            }
        }else{
            if(s4[2]=='D' || s4[2]=='F'){
                cout<<"1111";
            }else{
                cout<<"1100";
            }
        }
    }
}
