#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
string s1,c1,s2,c2;
cin>>s1>>s2>>c1>>c2;
if(si==c1){
cout<<1;
else
cout<<0;
if(s2==c2||s2/10==c2/10&&s2%10-c2%10<1)
cout<<111;
else if(s2/10!=c2/10)
cout<<000;
else if(s2%10-c2%10>1||c2%10-s2%10>1)
cout<<110;
}
return 0;
}
