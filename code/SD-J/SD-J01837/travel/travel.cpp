#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string p1,p2;
char p3,p4;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	p1+=s1[0];
	p1+=s1[1];
	p2+=s2[0];
	p2+=s2[1];
	p3 = s1[2];
	p4 = s2[2];
	if(c1==c2){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(c1==c2 && p1==p2){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(c1==c2 && p1==p2 && (((p3>='A' && p3<='C')&&(p4>='A' && p4<='C'))||((p3>='D' && p3<='F')&&(p4>='D' && p4<='F')))){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(c1==c2 && p1==p2 && (((p3>='A' && p3<='C')&&(p4>='A' && p4<='C'))||((p3>='D' && p3<='F')&&(p4>='D' && p4<='F'))) && ((p3 == 'A' && p4 == 'B') || (p3=='B'&&p4=='A') || (p3=='B'&&p4=='C') || (p3=='D'&&p4=='F') || (p3=='F'&&p4=='D'))){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
} 
