#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<1;
	else cout<<0;
	string l1,l2;
	l1+=s1[0];
	l1+=s1[1];
	l2+=s2[0];
	l2+=s2[1];
	if(c1==c2&&l1==l2)cout<<1;
	else cout<<0;
	char a1,a2;
	a1=s1[2];
	a2=s2[2]; 
	if(((a1>='A'&&a1<='C'&&a2>='A'&&a2<='C')||((a1=='D'||a1=='F')&&(a2=='D'||a2=='F')&&a1!=a2))&&c1==c2&&l1==l2)cout<<1;
	else{
		cout<<0<<0;
		return 0;
	}
	if(abs(int(a1)-int(a2))==1||(a1=='D'&&a2=='F')||(a1=='F'&&a2=='D'))cout<<1;
	else cout<<0;
	return 0;
}
