#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string a;
string b;
char x,y;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);

	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<"1";
		a+=s1[0];
		a+=s1[1];
		b+=s2[0];
		b+=s2[1];
		if(a==b)
		{
			cout<<"1";
			x=s1[2];
			y=s2[2];
			if((x<='C'&&y<='C')||(x>'C'&&y>'C'))
			{
				cout<<"1";
				if((x>y&&x-y==1)||(x<y&&y-x==1))
				{
					cout<<1;
					return 0;
				}
				cout<<"0";
				return 0;
			}
			cout<<"00";
			return 0;
		}
		cout<<"000";
		return 0;
	}
	cout<<"0000";
	return 0;
}
