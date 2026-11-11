#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in.txt","r",stdin);	
	freopen("travel.out.txt","w",stdout);
	string c1,c2,c3,c4;
	cin>>c1>>c2>>c3>>c4;
	int a=c2[2]-'A';
	int b=c4[2]-'A';
	if(c1==c3)
	{
		cout<<1;
		if(c2[0]==c4[0] && c2[1]==c4[1])
		{
			cout<<1;
			if(a+b<3 || a+b==7)
			{
				cout<<1;
				if(abs(a-b)==1)
				{
					cout<<1;
				}
				else cout<<0;
			}
			else cout<<0;
		}
		else cout<<0;
	}
	else cout<<0;
}


