#include <bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
bool a=0,b=0,c=0;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0);
cin>>s1>>s2>>s3>>s4;
if(s1==s3)
{ 
	cout<<1;
	a=1;
}
else cout<<0;
if(a && s2[0]==s4[0] && s2[1]==s4[1])
{ 
	cout<<1;
	b=1;
}
else cout<<0;
if(b && ((s2[2]<='C' && s4[2]<='C') || (s2[2]>='D' && s4[2]>='D')))
{ 
	cout<<1;
	c=1;
}
else cout<<0;
if(c && (abs(s2[2]-s4[2])==1))
{ 
	cout<<1;
}
else cout<<0;
return 0;
}
