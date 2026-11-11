#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	int a;
	if(c1==c2) 
	{
		a=1;
		cout<<'1';
	}
	else 
	{
		a=0;
		cout<<"0000";
		return 0;
	}
	int x=(int)(s1[0]-'0')*10+(int)(s1[1]-'0');
	int y=(int)(s2[0]-'0')*10+(int)(s2[1]-'0');
	if((x==y)&&(a==1)) cout<<'1';
	else 
	{
		a=0;
		cout<<"000";
		return 0;
	}
	if((s1[2]<='C'&&s2[2]>='D')||(s1[2]>='D'&&s2[2]<='C'))
	{
		a=0;
		cout<<"00";
		return 0;
	}
	else 
	{
		a=1;
		cout<<'1';
	}
	if(((abs((int)s1[2]-(int)s2[2])==1)||((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')))&&(a==1)) cout<<'1';
	else cout<<'0';
	return 0;
} 
