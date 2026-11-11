#include<bits/stdc++.h>
using namespace std;
string a1,a2,s1,s2;
int p1,p2,g1,g2,k,f;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>s1>>a2>>s2;
	for(int i=0;i<a1.size();i++){
		p1=p1*10+(a1[i]-'0');
	}
	for(int i=0;i<a2.size();i++){
		p2=p2*10+(a2[i]-'0');
	}
	if(p1==p2) cout<<1;
	else cout<<0;
	g1=(s1[0]-'0')*10+(s1[1]-'0');
	g2=(s2[0]-'0')*10+(s2[1]-'0');
	if(p1==p2&&g1==g2) cout<<1;
	else cout<<0;
	if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C') f=1;
	else if(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F') f=1;
	else f=0;
	if(p1==p2&&g1==g2&&f==1) cout<<1;
	else cout<<0;
	if(s1[2]=='A'&&s2[2]=='B') k=1;
	else if(s1[2]=='B'&&s2[2]=='C') k=1;
	else if(s1[2]=='D'&&s2[2]=='F') k=1;
	else if(s2[2]=='A'&&s1[2]=='B') k=1;
	else if(s2[2]=='B'&&s1[2]=='C') k=1;
	else if(s2[2]=='D'&&s1[2]=='F') k=1;
	else k=0;
	if(p1==p2&&g1==g2&&f==1&&k==1) cout<<1;
	else cout<<0; 
	return 0;
}