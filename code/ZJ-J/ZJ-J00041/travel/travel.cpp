#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s1,s2,s3,s4,s5,s6;
char c1,c2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>s1>>s2>>s3>>s4;
	s5=s2[0]+s2[1];		
	c1=s2[2];
	s6=s4[0]+s4[1];		
	c2=s4[2];
	if(c1>c2)swap(c1,c2);
	if(s1==s3)cout<<1;
	else cout<<0;
	if(s5==s6&&s1==s3)cout<<1;
	else cout<<0;
	if(s1==s3&&s5==s6&&c1<='C'&&c2<='C')cout<<1;
	else if(s1==s3&&s5==s6&&c1>='D'&&c2>='D')cout<<1;
	else cout<<0;
	{
		if(s1==s3&&s5==s6&&c1=='A'&&c2=='B')cout<<1;
		else if(s1==s3&&s5==s6&&c1=='B'&&c2=='C')cout<<1;
		else if(s1==s3&&s5==s6&&c1=='D'&&c2=='F')cout<<1;
		else cout<<0;
	}
	return 0;
}
