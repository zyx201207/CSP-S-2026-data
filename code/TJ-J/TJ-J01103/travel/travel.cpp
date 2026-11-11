#include<bits/stdc++.h>
using namespace std;
bool f1,f2,f3,f4;
string s1,s2;
int c1,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int l1=(s1[0]-'0')*10+(s1[1]-'0');
	int l2=(s2[0]-'0')*10+(s2[1]-'0');
	char r1=s1[2],r2=s2[2];
	f1=(c1==c2);
	f2=(f1&&l1==l2);
	f3=(f2&&(r1>='A'&&r1<='C'&&r2>='A'&&r2<='C')||((r1=='D'&&r2=='F')||(r1=='F'&&r2=='D')));
	f4=(f3&&((r1>='A'&&r1<='C'&&r2>='A'&&r2<='C'&&abs(r1-r2)==1)||((r1=='D'&&r2=='F')||(r1=='F'&&r2=='D'))));
	cout<<f1<<f2<<f3<<f4;
	return 0;
} 
