#include <bits/stdc++.h>
using namespace std;
using ll=long long;
bool a,b,c,d;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	
	bool t=1;
	if(s1[2]<='C')
	{
		t=s2[2]<='C';
	}
	else
	{
		t=s2[2]>='D'; 
	}
	
	if(c1==c2)
	{
		a=1;
	}
	if(a && s1[0]==s2[0] && s1[1]==s2[1])
	{
		b=1;
	}
	if(a && b && t)
	{
		c=1;
	}
	if(a && t && s2[2]-s1[2]==1)
	{
		d=1; 
	}
	cout << a << b << c << d;
	return 0;
}





