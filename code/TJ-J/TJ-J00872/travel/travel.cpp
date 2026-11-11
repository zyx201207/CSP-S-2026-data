#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string ca,sa,cb,sb;
	cin>>ca>>sa>>cb>>sb;
	if(ca==cb) 
	{
			cout <<1;
		//cout <<1<<((sa[0]-'0')*10+(sa[1]-'0'))/5;
		if(((sa[0]-'0')*10+(sa[1]-'0'))/5==((sb[0]-'0')*10+(sb[1]-'0'))/5)
		{
			cout <<1;
			if((sa[2]<='C'&&sb[2]<='C')||(sa[2]>'C'&&sb[2]>='C'))
			{
				cout <<1;
				if(abs(sa[2]-sb[2])==1&&(sa[2]!='C'&&sb[2]!='D'))
				{
					cout <<1;
				}
				else cout <<0;
			}
			else cout <<0<<0;
		}
		else cout <<0<<0<<0;
	}
	else cout <<0<<0<<0<<0;
	
	return 0;
	
}
