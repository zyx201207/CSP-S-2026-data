#include <bits/stdc++.h>
using namespace std;
string cmp;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
        cmp+='1';
    if(c1!=c2)
        cmp+='0';
    for(int i=0;i<=s1.size();i++){
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            cmp+='1';
        }
        else{
            cmp+='0';
        }
    }
    for(int i=0;i<=s1.size();i++){
        if(s1[2]=='A'&&s2[2]=='B'||s2[2]=='C'||s1[2]=='D'&&s2[2]=='F'||s2[2]=='A'&&s1[2]=='B'||s1[2]=='C'||s2[2]=='D'&&s1[2]=='F'){
            cmp+='1';
        }
        else{
            cmp+='0';
        }
    }
    for(int i=0;i<=s1.size();i++){
        if(abs(s1[2]-s2[2]==1)&&cmp[2]=='1'){
            cmp+='1';
        }
        else{
            cmp+='0';
        }
    }
    cout<<cmp;
    return 0;
}
