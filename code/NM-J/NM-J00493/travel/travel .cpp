#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string R_c,R_a,X_c,X_a;
	cin>>R_c>>R_a>>X_c>>X_a;
	if(R_c==X_c)
	{
		cout<<"1";	
		if(R_a[0]==X_a[0]&&R_a[1]==X_a[1])
		{
			cout<<"1";
			if(R_a[2]<'D'&&X_a[2]<'D' || R_a[2]>'C'&&X_a[2]>'C')
			{
				cout<<"1";
				int a=R_a[2],b=X_a[2];
				if(a-b==1 || b-a==1)
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
