#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int q1=0,q2=0,q3=0,q4=0;
	int a1=s1[0]-'0';
	int a2=s1[1]-'0';
	int a3=s1[2]-64;
	int b1=s2[0]-'0';
	int b2=s2[1]-'0';
	int b3=s2[2]-64;
	if(a3==4)
	{
		a3=5;
	}
	if(b3==4)
	{
		b3=5;
	}
	int l1=10*a1+a2;
	int l2=10*b1+b2;
	if(c1==c2)
	{
		q1=1;
		if(l1==l2)
		{
			q2=1;
			if((a3<=3&&b3<=3)||(a3>=4&&b3>=4))
			{
				q3=1;
				if(abs(a3-b3)==1)
				{
					q4=1;
				}
			}
		}
	}
	cout << q1 << q2 << q3 << q4 << endl;
	return 0;
}
