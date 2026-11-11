#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int c3,c4,s3,s4;
int a,b;
bool a1,a2,a3,a4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>s1>>s2;
	c3=(c1[0]-'0')*10+(c1[1]-'0');
	c4=(c2[0]-'0')*10+(c2[1]-'0');
	s3=(s1[0]-'0')*10+(s1[1]-'0');
	s4=(s2[0]-'0')*10+(s2[1]-'0');
	a=s1[2]-'A'+1;
	b=s2[2]-'A'+1;
	if(c3==c4) a1=1;
	if(a1 && s3==s4) a2=1;
	if(a2 && ((a<=3 && b<=3)|| (a>3 && b>3))) a3=1;
	if(a3 && (a+1==b || b+1==a)) a4=1;
	cout<<a1<<a2<<a3<<a4;
	return 0;
}
