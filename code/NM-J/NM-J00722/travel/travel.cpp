#include <bits/stdc++.h>
using namespace std;
int c1,c2,ch1,ch2,ch3;
string s1,s2;
char ss1,ss2;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
        ch1=1;
    }else{
        cout<<0;
    }
    ss1=s1[2];
    ss2=s2[2];
    int s11=(s1[0]-'0')*10+(s1[1]-'0');
    int s22=(s2[0]-'0')*10+(s2[1]-'0');
    if(s11==s22){
        cout<<1;
        ch2=1;
    }else{
        cout<<0;
    }
    if(abs(ss1-ss2)==1&&!(ss1=='C'&&ss2=='D')&&!(ss2=='C'&&ss1=='D')){
        cout<<1;
        ch3=1;
    }else{
        cout<<0;
    }
    if(ch1==1&&ch2==1&&ch3==1){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}
