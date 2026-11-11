#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define str string
#define lf double
void op(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
}
bool q1,q2,q3,q4;
str c1,s1,c2,s2;
ll cw(char c){
    if(c=='A'||c=='B'||c=='C'){
        return 1;
    }else if(c=='D'||c=='F'){
        return -1;
    }
    return 0;
}
str s="ABCDF";
bool ovo(char c1,char c2){
    for(ll i=0;i+1<s.size();++i){
        if(s[i]==c1){
            return s[i+1]==c2;
        }else if(s[i]==c2){
            return s[i+1]==c1;
        }
    }
    return 0;
}
int main(){
    op();
    cin>>c1>>s1>>c2>>s2;
    if(c1[0]==c2[0]&&c1[1]==c2[1]){
        q1=1;
    }//PD Che1xiang1 Shi4fou3 ==
    if(q1&&s1[0]==s2[0]&&s1[1]==s2[1]){
        q2=1;
    }//PD Pai2hao4 Shi4fou3 ==
    if(q2&&cw(s1[2])==cw(s2[2])){
        q3=1;
    }//PD Shi4fou3 be same Ce4
    if(q3&&ovo(s1[2],s2[2])){
        q4=1;
    }
    cout<<q1<<q2<<q3<<q4;
    return 0;
}
/*
abcdefghijklmnopqrstuvwxyz
1234567890
~!@#$%^&*()-=_+`/,.<>\{}[];':"
operator
*/
