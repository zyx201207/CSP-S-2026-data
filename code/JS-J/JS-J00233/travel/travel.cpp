#include<bits/stdc++.h>
using namespace std;
string s1[2],s2[2];
int main(){
    int c1,c2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==s1){
        cout<<1;
        if(s1[1]==s2[1]&&s1[0]==s2[0]){
           cout<<1;
           if(s1[2]+1==s2[2]&&s1[2]!+='C'||s2[2]+1==s1[2]&&s2[2]!+='C') cout<<11;
           else if(s1[2]=='A'&&s2[2]=='C'||s1[2]=='C'&&s2[2]=='A') cout<<10;
           else cout<<00;
        }
        else cout<<000;
    }    
    else cout<<0000;
    return 0;
}
