#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int pd=0;
    string s1,s2,s3,s4;
    cin>>s1>>s2>>s3>>s4;
    if(s1==s3&&s1!="01"&&s1!="03") cout<<1;
    else{
        cout<<"0000";
        return 0;
    }
    if(s2[0]==s4[0]&&s2[1]==s4[1]){
        cout<<1;
    }
    else{
        cout<<"000";
        return 0;
    }
    if(((s2[2]<='C'&&s4[2]<='C')||(s2[2]>='D'&&s4[2]>='D'))) cout<<1;
    else{
        cout<<"00";
        return 0;
    }
    if(abs((int)s2[2]-s4[2])==1&&pd==1)cout<<1;
    else cout<<0;
    return 0;
}
