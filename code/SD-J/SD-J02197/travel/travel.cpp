#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,d;
long long a=0;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<"1";
		a++;		
	}
	else
	cout<<"0";
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&a==1)
	{
		cout<<"1";
		a++;	
	}
	else
	cout<<"0";
	if((s1[2]<='C'&&s2[2]<='C'&&a==2)||(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F'&&a==2))
	{
		cout<<"1";
		a++;
	}
	else
	cout<<"0";
	if(abs(s1[2]-s2[2])==1&&a==3)
	cout<<"1";
	else
	cout<<"0";
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
