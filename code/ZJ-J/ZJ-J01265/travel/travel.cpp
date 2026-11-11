#include<bits/stdc++.h>
using namespace std;
int cr,cx;
char sr[5],sx[5];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cr>>sr>>cx>>sx;
	if(cr==cx)
	{
		cout<<1;
		if(sr[0]==sx[0] and sr[1]==sx[1])
		{
			cout<<1;
			if((sx[2]-'A'<=2 and sr[2]-'A'<=2) or (sx[2]-'A'>=3 and sr[2]-'A'>=3))
			{
				cout<<1;
				if(abs(sr[2]-sx[2])==1)
				{
					cout<<1;
				}
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
	{
		cout<<"0000";
	}
	return 0;
}