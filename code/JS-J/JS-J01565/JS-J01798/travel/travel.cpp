#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<"1";
    }else{
        cout<<"0000";
        return 0;
    }
    string t1="",t2="";
    for(int i=0;i<2;i++){
        t1+=s1[i];
        t2+=s2[i];
    }
    if(t1==t2){
        cout<<"1";
    }else{
        cout<<"000";
        return 0;
    }
    string s3="",s4="";
    for(int i=2;i<3;i++){
        s3+=s1[i];
        s4+=s2[i];
        break;
    }
    if((s3=="D"&&s4=="F")||(s3=="A"&&s4=="B")||(s3=="A"&&s4=="C")||(s3=="F"&&s4=="D")||(s3=="B"&&s4=="A")||(s3=="C"&&s4=="A")||(s3=="C"&&s4=="B")||(s3=="B"&&s4=="C")){
        cout<<1;
    }else{
        cout<<0;
    }
    if((s3=="D"&&s4=="F")||(s3=="F"&&s4=="D")||(s3=="A"&&s4=="B")||(s3=="B"&&s4=="A")||(s3=="B"&&s4=="C")||(s3=="C"&&s4=="B")){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}

