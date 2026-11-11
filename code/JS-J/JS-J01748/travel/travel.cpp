

#include<bits/stdc++.h>
using namespace std;
bool f=1;
string s="";
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2) s+="0",f=0;
    else s+="1";
    if((s1[0]==s2[0])&&(s1[1]==s2[1])&&(f!=0)) s+="1";
    else s+="0",f=0;
    if((s1[2]<='C')&&(s2[2]<='C')&&(f!=0)){
       s+="1";

    }else if((s1[2]>'C')&&(s2[2]>='C')&&(f!=0)){
        s+="1";

    }else s+="0";
    if(abs(s1[2]-s2[2])==1) s+="1";
    else s+="0";
    cout<<s;
    return 0;
}
