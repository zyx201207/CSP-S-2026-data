#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
    string s1,s2,c1,c2;
    cin>>c1>>s1>>c2>>s2;

    if(c1[0]!=c2[0]){
        cout<<"0000";
        return 0;
    }
    else if(c1[1]!=c2[1]){
        cout<<"0000";
        return 0;
    }
    else{
        if(s1[0]!=s2[0]){
            cout<<"1000";
            return 0;
        }
        else if(s1[1]!=s2[1]){
            cout<<"1000";
            return 0;
        }
        else if(s1[2]<='C' && s2[2]<='C' || s1[2]>'C' && s2[2]>'C'){
            if(s1[2]=='A'&& s2[2]=='B'){
                cout<<"1111";
                return 0;
            }
            else if(s1[2]=='B'&& s2[2]=='C'){
                cout<<"1111";
                return 0;
            }
            else if(s1[2]=='D'&& s2[2]=='F'){
                cout<<"1111";
                return 0;
            }
            else{
                cout<<"1110";
                return 0;
            }
        }
        else{
            cout<<"1100";
            return 0;
        }
    }
    return 0;
}
