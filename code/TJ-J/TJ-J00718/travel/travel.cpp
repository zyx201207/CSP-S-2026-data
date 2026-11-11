#include <bits/stdc++.h>
using namespace std;
int main(){
freopen("travel","r",stdin);
freopen("travel","r",stdout);
string c1,s1,c2,s2;
cin>>c1>>s1>>c2>>s2;
if(c1==c2)cout<<1;
else cout<<0;
a=s1[0]+s1[1];
b=s2[0]+s2[1];

if(a==b)cout<<1;
else cout<<0;
 f=s1[2];
 g=s2[2];
if((f==D&&g=E)||(f==A&&g==B)||(f==A&&g==C)||(f==B&&g==A)||(f==B&&g==C)||(f==E&&g==D)||(f==C&&f==A)||(f==C&&g==B))cout<<1;
else cout<<0;
if((f==D&&g=E)||(f==A&&g==B)||(f==B&&g==A)||(f==B&&g==C)||(f==E&&g==D)||(f==C&&g==B))cout<<1;
else cout<<0;
return 0;
}
