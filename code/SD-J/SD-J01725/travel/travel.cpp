#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3)cout<<1;
	else cout<<0;
	string c1,c2;
	c1=s2[0]+s2[1];
	c2=s4[0]+s4[1];
	if((c1==c2)&&(s1==s3))cout<<1;
	else cout<<0;
	bool f1=0,f2=0;
	if(s2[2]>='A'&&s2[2]<='C')f1=1;
	if(s4[2]>='A'&&s4[2]<='C')f2=1;
	if((f1==f2)&&(c1==c2)&&(s1==s3))cout<<1;
	else cout<<0;
	if((abs(s2[2]-s4[2])==1)&&(f1==f2)&&(c1==c2)&&(s1==s3))cout<<1;
	else cout<<0;
}
