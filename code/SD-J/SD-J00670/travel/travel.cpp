#include<bits/stdc++.h>
using namespace std;
char a1[5],a2[5];
char b1[5],b2[5];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin>>a1[1]>>a1[2];
    cin>>b1[1]>>b1[2]>>b1[3];
    cin>>a2[1]>>a2[2];
    cin>>b2[1]>>b2[2]>>b2[3];
    if(a1[1]==a2[1]&&a1[2]==a2[2])
	{
		cout<<"1";
		if(b1[1]==b2[1]&&b1[2]==b2[2])
		{
			cout<<"1";
			if(((int)b1[3]<=67&&(int)b2[3]<=67)||((int)b1[3]>67&&(int)b2[3]>67))
			{
				cout<<"1";
				if((int)b1[3]-(int)b2[3]==1||(int)b2[3]-(int)b1[3]==1)
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
