#include<bits/stdc++.h>
using namespace std;
char a1,a2,a3,a4,a5,b1,b2,b3,b4,b5;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>a1>>a2>>a3>>a4>>a5>>b1>>b2>>b3>>b4>>b5;
	int a=(a1-'0')*10+(a2-'0'),aa=(a3-'0')*10+(a4-'0');
	int b=(b1-'0')*10+(b2-'0'),bb=(b3-'0')*10+(b4-'0');
	
	int p1,p2;
	if((a5-'A')>2) p1=(a5-'A')+10;
	else p1=(a5-'A');
	
	if((b5-'A')>2) p2=(b5-'A')+10;
	else p2=(b5-'A');
	
	if(a==b)
	{
		cout<<'1';
		if(aa==bb)
		{
			cout<<'1';
			if(abs(p1-p2)<5)
			{
				cout<<'1';
				if(abs(p1-p2)==1)
				{
					cout<<'1';
				}
				else
				{
					cout<<'0';
				}
			}
			else
			{
				cout<<"00";
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
