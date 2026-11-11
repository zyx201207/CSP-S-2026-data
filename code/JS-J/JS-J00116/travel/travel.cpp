#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>s1>>s2>>s3>>s4;
    char ss1=s2[2];
    char ss2=s4[2];
    char c1=max(ss1,ss2);
    char c2=min(ss1,ss2);
    s2.erase(2,1);
    s4.erase(2,1);
    if(s1=="02" && s3=="02"){
        cout<<"1";
    }
    else{
        cout<<"0000";
        return 0;
    }
    if(s2==s4){
        cout<<"1";
    }
    else{
        cout<<"000";
        return 0;
    }
    if((c1!='D' && c1!='F' && c2!='D' && c2!='F') || (c2=='D' && c1=='F')){
        cout<<"1";
    }
    else{
        cout<<"00";
        return 0;
    }
    if(c1-c2==1){
        cout<<"1";
    }
    else{
        cout<<"0";
    }
}
