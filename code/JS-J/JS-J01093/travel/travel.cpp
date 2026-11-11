#include<bits/stdc++.h>
using namespace std;
int che(char c){
    if('A'<=c&&c<='C')return 1;
    if(c=='D'||c=='F')return 2;
    return 0;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string sa1,sa2,sb1,sb2;
    cin>>sa1>>sa2>>sb1>>sb2;
    string ans="";
    if(sa1!=sb1) cout<<"0000";
    else{
        if(sa2[0]!=sb2[0]||sa2[1]!=sb2[1])cout<<"1000";
        else{
            if(che(sa2[2])!=che(sb2[2])) cout<<"1100";
            else{
                if(abs(sa2[2]-sb2[2])==2) cout<<"1110";
                else cout<<"1111";
            }
        }
    }
    return 0;
}
