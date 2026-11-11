#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string f1="0",f2="0",f3="0",f4="0";
	string ans;
	string c1,c2,s1,s2;
	string t1,t2;
	cin>>c1>>s1>>c2>>s2;
	t1=s1[0]+s1[1];
	t2=s2[0]+s2[1];
	if(c1==c2) f1="1";
	if(f1=="1"&&t1==t2) f2="1";
	if(f2=="1"&&((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'))) f3="1";
	if(f3=="1"&&abs(s1[2]-s2[2])==1) f4="1";
	cout<<f1<<f2<<f3<<f4;
	return 0;
}