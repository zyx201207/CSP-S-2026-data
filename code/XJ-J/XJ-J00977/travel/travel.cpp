#include<bits/stdc++.h>
using namespace std;
long long int c1,s1,i,flog,c;
string c2,s2;
int main()
{
	freopen("travel.in","f"stdin);
	freopen("travel.out","x"stdout);
	cin>>c1>>c2>>s1>>s2;
	if(c1==s1)
	cout<<'1';
	else
	cout<<'0';
	for(i=0;i<=1;i++)
	{
		if(c2[i]!=s2[i])
		{
			flog=1;
			break;
		}
	}
	if(flog==1)
	cout<<'0';
	else
	cout<<'1';
	if((c2[2]<='C'&&s2[2]<='C')||(c2[2]>='D'&&s2[2]>='D'))
	{
		c=1;
		cout<<'1';
	}
	else
	cout<<'0';
	if((c2[2]=='D'&&s2[2]=='F')||(c2[2]=='F'&&s2[2]=='D'))
	cout<<'1';
	else
	if((c2[2]-1==s2[2]||c2[2]+1==s2[2])&&c!=0)
	cout<<'1';
	else
	cout<<'0';
	return 0;
}