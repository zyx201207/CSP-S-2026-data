#include<bits/stdc++.h>
using namespace std;

const int N=200005;
string s1,s2,c1,c2;
int ans;

int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0);
cin>>c1>>s1>>c2>>s2;
if(c1==c2){
    ans+=1000;
    if(s1[0]==s2[0]&&s1[1]==s2[1]){
        ans+=100;
        if(((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))||((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F'))){
            ans+=10;
            if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D'))ans+=1;
        }
    }
}
cout<<ans;
return 0;
}
