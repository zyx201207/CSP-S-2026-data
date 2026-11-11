#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
string ans;
char a,b,a1,b1;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        ans+='1';
    }else{
        ans+='0';
    }

    for(int i=0;i<s1.size();i++){
        if(s1[i]>='0'&&s1[i]<='9'){
            a+=s1[i];
        }
    }
    for(int i=0;i<s2.size();i++){
        if(s2[i]>='0'&&s2[i]<='9'){
            b+=s2[i];
        }
    }
    if(a==b&&c1==c2){
        ans+='1';
    }else{
        ans+='0';
    }

    for(int i=0;i<s1.size();i++){
        if(s1[i]>='A'&&s1[i]<='Z'){
            a1+=s1[i];
        }
    }
    for(int i=0;i<s2.size();i++){
        if(s2[i]>='A'&&s2[i]<='Z'){
            b1+=s2[i];
        }
    }
    if((a==b&&c1==c2)&&((a1=='A'||a1=='B'||a1=='C')&&(b1=='A'||b1=='B'||b1=='C'))||((a1=='D'||a1=='F')&&(b1=='D'||b1=='F'))){
        ans+='1';
    }else{
        ans+='0';
    }

    if((a==b&&c1==c2)&&(a1=='A'&&b1=='B')||(a1=='B'&&b1=='C')||(b1=='A'&&a1=='B')||(b1=='B'&&a1=='C')||(a1=='D'&&b1=='F')||(b1=='D'&&a1=='F')&&(a1+'1'==b1-'0')||(b1+'1'==a1-'0')){
        ans+='1';
    }else{
        ans+='0';
    }
    cout<<ans;
    return 0;
}
