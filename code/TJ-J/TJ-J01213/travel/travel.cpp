#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool f,c,s;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(s1[2]=='F') s1[2]-=1;
	if(s2[2]=='F') s2[2]-=1;
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C') s1[3]=1;
	else s1[3]=0;
	if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C') s2[3]=1;
	else s2[3]=0;
	if(c1==c2&&c1!="01"&&c1!="16"&&c2!="01"&&c2!="16") cout<<1,f=1;
	else cout<<0;
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&f==1) cout<<1,c=1;
	else cout<<0;
	if(s1[3]==s2[3]&&f==1&&c==1) cout<<1,s=1;
	else cout<<0;
	if((s1[2]+1==s2[2]||s2[2]+1==s1[2])&&f==1&&c==1&&s==1) cout<<1;
	else cout<<0;
	return 0;
} 
