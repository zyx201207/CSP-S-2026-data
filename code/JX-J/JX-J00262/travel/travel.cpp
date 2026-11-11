#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
const int INF=1e9+5;
int flag1=0;
int flag2=0;
int flag3=0;
int check1(string s1,string s2){
    if(s1==s2){
        flag1=1;
        return 1;
    }
    return 0;
}
int check2(string s1,string s2){
    if(flag1==0){
        return 0;
    }
    if(s1[1]==s2[1]&&s1[0]==s2[0]){
        flag2=1;
        return 1;
    }
    return 0;
}
int check3(string s1,string s2){
    if(flag1==0){
        return 0;
    }
    if(flag2==0){
        return 0;
    }
    if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
        if(s2[2]!='F'&&s2[2]!='D'){
            flag3=1;
            return 1;
        }else{
            return 0;
        }
    }else{
        if(s2[2]!='A'&&s2[2]!='B'&&s2[2]!='C'){
            flag3=1;
            return 1;
        }else{
            return 0;
        }
    }
}
int check4(string s1,string s2){
    if(flag2==0){
        return 0;
    }
    if((s1[2]=='C'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='C')){
        return 0;
    }
    if(s1[2]+1==s2[2]||s1[2]-1==s2[2]){
        return 1;
    }else{
        return 0;
    }
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s1,s2,s3,s4;
    cin>>s1>>s2>>s3>>s4;
    cout<<check1(s1,s3);
    cout<<check2(s2,s4);
    cout<<check3(s2,s4);
    cout<<check4(s2,s4)<<endl;
    return 0;
}
