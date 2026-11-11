#include <bits/stdc++.h>
using namespace std;
freopen("travel.in","r","stdin")
freopen("travel.out","w","stdout")
int main() 
{
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a[0]==c[0])
	{
		if(a[1]==c[1])
		{
			cout<<"1";
			if(b[0]==d[0])
			{
				if(b[1]==d[1])
				{
					cout<<"1";
					int e=b[2]-'A';
					int r=d[2]-'A';
					int t=e-r;
					if(t>0)
					{
						t=t;
					}else
					{
						t=0-t;
					}
					if(e<=2&&r<=2)
					{
						cout<<"1";
						if(t==1)
						{
							cout<<"1";
						}else
						{
							cout<<"0";
						}
					}else if(e>2&&e<=4&&r>2&&r<=4)
					{
						cout<<"1";
						if(t==1)
						{
							cout<<"1";
						}else
						{
							cout<<"0";
						}
					}else
					{
						cout<<"00";
					}
				}else
				{
					cout<<"000";
				}
			}else
			{
				cout<<"000";
			}
		}else
		{
			cout<<"0000";
		}	
	}else
	{
		cout<<"0000";
	}
fclose("stdin")
fclose("stdout")
	return 0;
}
