#include<bits/stdc++.h>
using namespace std;
char c1,c2,s1[100],s2[100];
int c,d,n,i,m;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1[i]>>c2>>s2[i];
	if(c1=='02')
	c=1;
	else
	c=0;
	if(c2=='02')
	d=1;
	else
	d=0;
	if(s1[0]==s2[0]&&s1[1]==s2[1])
	n=1;
	else
	n=0;
	if(s1[2]==s2[2])
	{
		if(s1[2]+1==s2[2]||s2[2]+1==s1[2])
		m=1;
		else
		m=0;
	}
	cout<<c<<d<<n<<m;
}