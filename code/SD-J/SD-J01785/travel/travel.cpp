#include <iostream>
#include <cstdio>
using namespace std;
int a1,b1,a2,b2;
char c1,c2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>b1>>c1>>a2>>b2>>c2;
	cout<<(a1==a2)<<(a1==a2&&b1==b2)<<((a1==a2&&b1==b2)&&(c1<='C'&&c2<='C'||c1>'C'&&c2>'C'));
	if(a1==a2&&b1==b2&&(c1<='C'&&c2<='C'||c1>'C'&&c2>'C'))
	{
		cout<<((c1=='A'&&c2=='B')||(c1=='B'&&c2=='A')
			 ||(c1=='B'&&c2=='C')||(c1=='C'&&c2=='B')
		     ||(c1=='D'&&c2=='E')||(c1=='E'&&c2=='D'));
	}
	else cout<<0;
	return 0;
} 
