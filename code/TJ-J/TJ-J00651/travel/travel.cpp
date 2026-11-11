#include<bits/stdc++.h> 
using namespace std;
struct tra{
	string c;
	string s;
};
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	tra R;
	tra X;
	cin>>R.c>>R.s>>X.c>>X.s;
	if(R.c == X.c)
	{
		cout<<1;
		if(R.s[0]==X.s[0]&&R.s[1]==X.s[1])
		{
			cout<<1;
			if((R.s[2]<='C'&&X.s[2]<='C'))
			{
				cout<<1;
				if(R.s[2]+1==X.s[2]||R.s[2]-1==X.s[2])
				{
					cout<<1;
					
				}
				else
				{
					cout<<0;
				}
			}
			else if((R.s[2]+1=='D'&&X.s[2]=='D')||(X.s[2]+1=='D'&&R.s[2]=='D'))
			{
				cout<<0<<0;
			}
			else if(R.s[2]<='F'&&X.s[2]<='F'&&R.s[2]>='D'&&X.s[2]>='D') 
			{
				cout<<1<<1;;
				
			}
			else
			{
				cout<<0;
			}
		}
		else
		{
			cout<<0<<0<<0;
		}
	} 
	else
	{
		cout<<0<<0<<0<<0;
	}
	
	return 0;
}
