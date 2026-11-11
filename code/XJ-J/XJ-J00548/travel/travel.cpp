#include <bits/stdc++.h>
using namespace std ;

string c1 , s1 , c2 , s2 ;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2 ;
	if(c1==c2)
		cout << 1 ;
	else
	{
		cout << 0 ;
		cout << 0 ;
		cout << 0 ;
		cout << 0 ;
		return 0 ;
	}
	int r=0 , x=0 ;
	char r2 , x2 ;
	for(int i=1;i<=3;i++)
	{
		if(s1[i]>='0' && s1[i]<='9')
		{
			r*=10;	r+=s1[i]-'0';	
		}
		if(s1[i]>='A' && s1[i]<='Z')
		{
			r2=s1[i];	
		}
	}
	for(int i=1;i<=3;i++)
	{
		if(s2[i]>='0' && s1[i]<='9')
		{
			x*=10;	x+=s2[i]-'0';	
		}
		if(s2[i]>='A' && s1[i]<='Z')
		{
			x2=s2[i];
		}
	}
	if(r==x)
		cout << 1 ;
	else
		cout << 0 ;
	if(r2<='C'&&x2<='C')
		cout << 1 ;
	else if(r2>'C'&&r2<='F'&&x2>'C'&&x2<='F')
		cout << 1 ;
	else
	{
		cout << 0 ;
		cout << 0 ;
		return 0;
	}
	if(r2+1==x2||r2-1==x2)
		cout << 1 ;
	else
		cout << 0 ;
	
	return 0 ;
}