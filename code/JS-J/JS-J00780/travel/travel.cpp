#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>s2>>s3>>s4;
    if(s1==s3)cout<<"1";else {cout<<"0000"<<endl;return 0;}
    if(s2[0]+s2[1]==s4[0]+s4[1])cout<<"1";else{cout<<"000"<<endl;return 0;}
    if(s2[2]<=67&&s4[2]<=67)cout<<"1";
    else if(s2[2]>67&&s4[2]>67)cout<<"1";
    else {cout<<"00"<<endl;return 0;}
    if((int(s2[2]+1)==int(s4[2])||int(s2[2]-1)==int(s4[2]))&&(s2[2]!='C'||s2[2]!='D'))cout<<"1"<<endl;
    else cout<<"0"<<endl;
    return 0;
}
