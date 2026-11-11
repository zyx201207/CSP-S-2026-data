#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
    string s1,s2,s3,s4;
    cin>>s1>>s2>>s3>>s4;
    string ans="";
    if(s1==s3){
        ans+='1';
    }
    else{
        cout<<0<<0<<0<<0;
        return 0;
    }


    string ss="",sss="";
    for(int i=0;i<2;i++){
        ss+=s2[i];
        sss+=s4[i];
    }

    if(s1==s3&&ss==sss){
        ans+='1';
    }
    else{
        cout<<1000;
        return 0;
    }
    if(s1==s3&&ss==sss&&s2[2]>='A'&&s2[2]<='C'&&s4[2]>='A'&&s4[2]<='C'||s1==s3&&ss==sss&&s2[2]>='D'&&s2[2]<='F'&&s2[2]!='E'&&s4[2]>='D'&&s4[2]<='F'&&s4[2]!='E'){
        ans+='1';
    }
    else{
        cout<<1100;
        return 0;
    }
    if(s1==s3&&ss==sss&&s2[2]>='A'&&s2[2]<='C'&&s4[2]>='A'&&s4[2]<='C'&&abs(s4[2]-s2[2])==1||s1==s3&&ss==sss&&s2[2]>='D'&&s2[2]<='F'&&s2[2]!='E'&&s4[2]>='D'&&s4[2]<='F'&&s4[2]!='E'&&abs(s4[2]-s2[2])==1){
        ans+='1';
    }
    else{
        cout<<1110;
        return 0;
    }
    if(ans.size()==4) cout<<ans;
    return 0;
}
