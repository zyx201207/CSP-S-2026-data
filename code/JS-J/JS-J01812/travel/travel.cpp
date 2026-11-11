#include<bits/stdc++.h>
using namespace std;
int a,b,x,y,ans[4];
char u,v;
string s;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s;
    a=(s[0]-'0')*10+(s[1]-'0');
    cin>>s;
    x=(s[0]-'0')*10+(s[1]-'0');
    u=s[2];
    cin>>s;
    b=(s[0]-'0')*10+(s[1]-'0');
    cin>>s;
    y=(s[0]-'0')*10+(s[1]-'0');
    v=s[2];
    if(a==b){
        ans[0]=1;
    }
    if(a==b&&x==y){
        ans[1]=1;
    }
    if(a==b&&x==y&&((u<='C'&&v<='C')||(u>'C'&&v>'C'))){
        ans[2]=1;
    }
    if(a==b&&x==y&&u<='C'&&v<='C'&&(u=='B'||v=='B')){
        ans[3]=1;
    }
    if(a==b&&x==y&&u>'C'&&v>'C'){
        ans[3]=1;
    }
    for(int i=0;i<4;i++){
        cout<<ans[i];
    }
    return 0;
}
