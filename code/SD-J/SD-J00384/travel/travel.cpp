#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string friend1;
	string zuo1;
	string friend2;
	string zuo2;
	cin>>friend1;
	cin>>zuo1;
	cin>>friend2;
	cin>>zuo2;
	int f=0;
	if(friend1==friend2)
	{
		cout<<1;
		if(zuo1[0]==zuo2[0])
		{
			if(zuo1[1]==zuo2[1])
			{
				cout<<1;
				if((zuo1[2]=='A'&&zuo2[2]=='B')||(zuo1[2]=='B'&&zuo2[2]=='C')||(zuo1[2]=='D'&&zuo2[2]=='F')||(zuo1[2]=='A'&&zuo2[2]=='C')||(zuo1[2]=='B'&&zuo2[2]=='A')||(zuo1[2]=='C'&&zuo2[2]=='B')||(zuo1[2]=='F'&&zuo2[2]=='D')||(zuo1[2]=='C'&&zuo2[2]=='A'))
				{
					cout<<1;
					if((zuo1[2]=='A'&&zuo2[2]=='B')||(zuo1[2]=='B'&&zuo2[2]=='C')||(zuo1[2]=='D'&&zuo2[2]=='F')||(zuo1[2]=='B'&&zuo2[2]=='A')||(zuo1[2]=='C'&&zuo2[2]=='B')||(zuo1[2]=='F'&&zuo2[2]=='D'))
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
					cout<<0;
					cout<<0;
				}
			}
			else
			{
				cout<<0;
				cout<<0;
				cout<<0;
			}
		}
		else
		{
			cout<<0;
			cout<<0;
			cout<<0;
		}
	}
	else
	{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
