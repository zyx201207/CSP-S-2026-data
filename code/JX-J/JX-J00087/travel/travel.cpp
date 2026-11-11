#include<bits/stdc++.h>
using namespace std;
string s[10];
int ans;
bool check1(){
    return (s[2][0]==s[4][0])&&(s[2][1]==s[4][1]);
}
bool f(char c){
    return ('A'<=c&&c<='C');
}
bool check2(){
    char c1=s[2][2],c2=s[4][2];
    if(f(c1)&&f(c2))return 1;
    else if(c1+c2=='D'+'F')return 1;
    return 0;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s;
    for(int i=1;i<=4;i++)cin>>s[i];
    if(s[1]==s[3]){
       ans+=1000; 
        if(check1()){
            ans+=100;
            if(check2()){
                ans+=10;
                char c1=s[2][2],c2=s[4][2];
                if(abs(c1-c2)==1)ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}