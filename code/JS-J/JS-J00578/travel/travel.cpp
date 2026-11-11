#include<bits/stdc++.h>
using namespace std;
int c1,c2,d1,d2;
char s1,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>d1>>s1>>c2>>d2>>s2;
	if(c1==c2)
	{
		cout<<1;
		if(d1==d2)
		{
			cout<<1;
			if((s1<='C'&&s2<='C')||(s1>'C'&&s2>'C'))
			{
				cout<<1;
				if(s1+1==s2||s1-1==s2)
					cout<<1;
				else
					cout<<0;
			}
			else
				cout<<"00";
		}
		else
			cout<<"000";
	}		
	else
		cout<<"0000";
	return 0;
}
