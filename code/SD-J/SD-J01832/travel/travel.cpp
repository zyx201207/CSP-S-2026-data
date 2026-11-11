#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4,ss,sss;
bool b1,b2,b3,b4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
cin>>s1>>s2>>s3>>s4;
b1=b2=b3=b4=1;
ss=s2[0]+s2[1],sss=s4[0]+s4[1];
//if(s2[2]>='A'&&s2[2]<='C')s2[2]=1;
//else s2[2]=0;
//if(s4[2]>='A'&&s4[2]<='C')s4[2]=1;
//else s4[2]=0;
s2[2]=s2[2]-'A'+1;
s4[2]=s4[2]-'A'+1;

if(s1!=s3)b1=b2=b3=b4=0;
else if(ss!=sss)b2=b3=b4=0;
else if((s2[2]<4)!=(s4[2]<4))b3=b4=0;
else if(s2[2]-s4[2]==1||s4[2]-s2[2]==1)b4=1;
else b4=0;

cout<<b1<<b2<<b3<<b4;
	return 0;
}
