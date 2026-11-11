#include<bits/stdc++.h>
using namespace std;
int main(){

    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);


    int c1,c2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    string t;
    if(c1==c2){
        t+="1";
        if(s1[1]==s2[1]){
            t+="1";
            if(s1[2]>='D'&&s2[2]>='D'){
                t+="1";
                if(s1[2]+1==s2[2]||s1[2]-1==s2[2]){
                    t+="1";
                }
                else{
                    t+="0";
                }
            }
            else if(s1[2]<='C'&&s2[2]<='C'){
                t+="1";
                if(s1[2]+1==s2[2]||s1[2]-1==s2[2]){
                    t+="1";
                }
                else{
                    t+="0";
                }
            }
            else{
                t+="00";
            }
        }
        else{
            t+="000";
        }
    }
    else{
        cout<<"0000";
        return 0;
    }
    cout<<t;
    return 0;
}
