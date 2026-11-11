//lishuyu 82zhong SN-J00711
#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
string a,b;//s1,s2
string c,d;//01 02 03
char n,m;
	cin>>c1>>a>>c2>>b;
	c+=a[0],c+=a[1];
	d+=b[0],d+=b[1];
	
	n = a[2];
	m = b[2];
	if(c1 == c2) cout<<1;
	else cout<<0;
	if(c == d) 
	{
		cout<<1;
		if((n>='A' && n<='C' && m>='A' && m<='C')
		|| (n>='D' && n<='F' && m>='D' && m<='F'))
		{
			cout<<1;
			if(abs(n-m) == 1) cout<<1;
			else cout<<0;
		}
		else cout<<0<<0;
	}
	else cout<<0<<0<<0;
	return 0;
			
}

