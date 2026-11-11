//- About the Universe -
//- I'll tell you, about the universe. -
#include<bits/stdc++.h>
using namespace std;
string ca,sa,cb,sb;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ca>>sa>>cb>>sb;
	if(ca==cb)
	{
		cout<<1;
		int a=(sa[0]-'0')*10+(sa[1]-'0');
		int b=(sb[0]-'0')*10+(sb[1]-'0');
		if(a==b)
		{
			char qwq=sa[2];
			char qaq=sb[2];
			cout<<1;
			if(qwq>qaq)
			{
				swap(qwq,qaq);
			}
			if(qwq<='C'&&qaq<='C')
			{
				cout<<1;
			}
			else if(qwq>='D'&&qaq>='D')
			{
				cout<<1;
			}
			else
			{
				cout<<0;
			}
			if((qwq=='A'&&qaq=='B')||(qwq=='B'&&qaq=='C')||(qwq=='D'&&qaq=='F'))
			{
				cout<<1;
			}
			else
			{
				cout<<0;
			}
		}
		else
		{
			cout<<"000";
		}
	}
	else
	{
		cout<<"0000";
	}
	return 0;
}
