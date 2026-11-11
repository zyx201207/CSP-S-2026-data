#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
   cin>>c1>>s1>>c2>>s2;
    string ans="0000";
    if(c1==c2)ans[0]='1';
    if(s1[0]==s2[0]&&s1[1]==s2[1]){
        ans[1]='1';
        char x=s1[2],y=s1[2];
        if((x=='D'&&y=='F')||(x=='F'&&y=='D')){
            ans[2]='1';
            ans[3]='1';
        }
        if(x>='A'&&x<='C'&&y>='A'&&y<='C'){
            ans[2]='1';
            if((x=='A'&&y=='B')||(x=='B'&&y=='A')||(x=='C'&&y=='B')||(x=='B'&&y=='C'))ans[3]='1';
        }
    }
    cout<<ans;
    return 0;
}
//travel