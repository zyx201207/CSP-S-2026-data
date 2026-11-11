#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
bool f,s,t,l; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)f=1;
	if(f==1&&s1[0]==s2[0]&&s1[1]==s2[1])s=1;
	if(s==1&&(s1[2]>='A'&&s2[2]>='A'&&s1[2]<='C'&&s2[2]<='C')||s1[2]>='D'&&s2[2]>='D'&&s1[2]<='F'&&s2[2]<='F')t=1;
	if(t==1&&abs(s1[2]-s2[2])==1)l=1;
	cout<<f<<s<<t<<l;
	return 0;
} 
