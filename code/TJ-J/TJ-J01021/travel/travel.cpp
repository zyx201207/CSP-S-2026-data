#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string q,a,z,w;
	cin>>q>>a>>z>>w;
	if(q==z)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	if(q==z)
	{
		if(a[0]==w[0])
		{
			if(a[1]==w[1])
			{
				cout<<"1";
			}
			else
			{
				cout<<"0";
			}
		}
		else
		{
			cout<<"0";
		}
	}
	else
	{
		cout<<"0";
	} 

	if(q==z)
	{
		if(a[0]==w[0])
		{
			if(a[1]==w[1])
			{
				if((a[2]=='D'||a[2]=='F')&&(w[2]=='D'||w[2]=='F'))
				{
					cout<<"1";
				}
				else if((a[2]=='A'||a[2]=='B'||a[2]=='C')&&(w[2]=='A'||w[2]=='B'||w[2]=='C'))
				{
					cout<<"1";
				}
				else
				{
					cout<<"0";
				}
			}
			else
			{
				cout<<"0";
			}
		}
		else
		{
			cout<<"0";
		}
	}
	else
	{
		cout<<"0";
	}
	if(q==z)
	{
		if(a[0]==w[0])
	{
		if(a[1]==w[1])
		{
			if(a[2]=='A'&&w[2]=='B')
			{
				cout<<"1";
			}
			else if(a[2]=='B'&&(w[2]=='A'||w[2]=='C'))
			{
				cout<<"1";
			}
			else if(a[2]=='C'&&w[2]=='B')
			{
				cout<<"1";
			}
			else if(a[2]=='D'&&w[2]=='F')
			{
				cout<<"1";
			}
			else if(a[2]=='F'&&w[2]=='D')
			{
				cout<<"1";
			}
			else if(w[2]=='A'&&a[2]=='B')
			{
				cout<<"1";
			}
			else if(w[2]=='B'&&(a[2]=='A'||a[2]=='C'))
			{
				cout<<"1";
			}
			else if(w[2]=='C'&&a[2]=='B')
			{
				cout<<"1";
			}
			else if(w[2]=='D'&&a[2]=='F')
			{
				cout<<"1";
			}
			else if(w[2]=='F'&&a[2]=='D')
			{
				cout<<"1";
			}
			else
			{
				cout<<"0";
			}
		}
		else
		{
			cout<<"0";
		}
	}
	else
	{
		cout<<"0";
	}
	}
	else
	{
		cout<<"0";
	}
	return 0;
}
