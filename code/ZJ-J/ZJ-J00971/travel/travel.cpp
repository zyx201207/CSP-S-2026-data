#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a=0,b=0,c=0,d=0;
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) a=1;
	else a=0;
	if(a==1&&s1[0]==s2[0]&&s1[1]==s2[1]) b=1;
	else b=0;
	if(b==1&&(s1[2]>='D'&&s2[2]>='D'||s1[2]<='C'&&s2[2]<='C')) c=1;
	else c=0;
	if(c==1&&abs(s1[2]-s2[2])==1) d=1;
	else d=0;
	cout<<a<<b<<c<<d<<"\n";
	return 0;
}
