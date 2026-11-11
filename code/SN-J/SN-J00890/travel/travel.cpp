#include <iostream>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string ca, sa, cb, sb;
	cin>>ca>>sa>>cb>>sb;
	if(ca==cb){
		cout<<1;
		if(sa>sb)
		{
			cout<<1;
			if(sa<sb)
			{
				cout<<"1";
				if(sa>sb)
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
