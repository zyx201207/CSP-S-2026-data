#include<bits/stdc++.h>
using namespace std;
int c1,c2,x1,x2;
string s1,s2;
char a,b;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<s1.size()-1;i++)x1=x1*10+(s1[i]-'0');
	for(int i=0;i<s2.size()-1;i++)x2=x2*10+(s2[i]-'0');
	a=s1[2];b=s2[2];
	if(c1!=c2)cout<<"0000"<<'\n';
	else
	{
		if(x1!=x2)cout<<"1000"<<'\n';
		else
		{
			if((a=='D'||a=='F')&&(b=='A'||b=='B'||b=='C')||(a=='A'||a=='B'||a=='C')&&(b=='D'||b=='F'))cout<<"1100"<<'\n';
			    else
			    {
			    	if(a==b+1||b==a+1||a=='D'&&b=='F'||a=='F'&&b=='D')cout<<"1111"<<'\n';
			    	    else cout<<"1110"<<'\n';
				}
		}
	}
	return 0;
}
