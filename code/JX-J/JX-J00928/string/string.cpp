#include <bits/stdc++.h>
using namespace std;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
int n;
string s;
char s1[20],s2[20];
cin>>n;
for(int i=0;i<=n;i++){
    getline(cin,s);
    s1[i]=s[0];
    s2[i]=s[2];
}
switch(n){
case 1:cout<<0;break;
case 2:if(s2[1]==s2[2]){
       cout<<0;
       break;
       }
       else{
        if(s1[1]>s1[2])
            cout<<(int)s1[2]-'0';
        else
            cout<<(int)s1[1]-'0';
        break;
       }
}

return 0;
}
